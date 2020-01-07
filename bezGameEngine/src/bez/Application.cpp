#include <stdafx.hpp>

#include "Application.hpp"

#include <bez/Events/Event.hpp>
#include <bez/Events/KeyEvent.hpp>
#include <bez/Events/MouseEvent.hpp>
#include <bez/Events/WindowEvent.hpp>

namespace bez {

Application *Application::m_instance = nullptr;

Application::Application() {
  m_isRunning = false;
  m_instance = this;
}

Application::~Application() { m_window.reset(); }

/// Loads necessary resouces, creating and configurating the window
void Application::init(const char *p_title, unsigned int p_width,
                       unsigned int p_heigth) {

  m_window = Window::create(p_title, p_width, p_heigth);

  if (m_window == nullptr)
    return;

  m_isRunning = m_window->isReady();

  /// set function that receives all events emmited from the window
  m_window->setEventCallback(
      std::bind([](auto obj, Event &e) { obj->onEvent(e); }, this,
                std::placeholders::_1));
}

/// Application main Loop
void Application::run() {
  if (m_window == nullptr) {
    /// Failed to create Window
    BEZ_CORE_CRIT("There is no Window to run");
    return;
  }

  if (m_isRunning) {
    while (isRunning()) {
      m_window->clear();
      m_window->onUpdate();
      for (auto &layer : m_layerStack) {
        layer->onUpdate();
        if (!layer->isActive())
          m_layerStack.popLayer(layer);
      }

      if (m_layerStack.size() == 0)
        // Stops application if there is no layers on the stack
        stop();

      m_window->render();
    }
  }
}

/// Function set as callback to window events
void Application::onEvent(Event &event) {
  EventDispatcher dispatcher(event);

  // The application layer handles Window closed and window resized events, all
  // other events are passed to other layers

  dispatcher.dispatch<WindowClosedEvent>(std::bind(
      [](auto obj, WindowClosedEvent &e) {
        obj->m_isRunning = false;
        return true;
      },
      this, std::placeholders::_1));

  dispatcher.dispatch<WindowResizedEvent>(std::bind(
      [](auto obj, WindowResizedEvent &e) {
        obj->m_window->resize(e.getWindowSize());
        return true;
      },
      this, std::placeholders::_1));

  for (auto it = m_layerStack.rbegin(); it != m_layerStack.rend(); ++it) {
    (*it)->onEvent(event);
    if (event.isHandled())
      break;
  }
}

bool Application::isRunning() { return m_isRunning; }

void Application::pushLayer(Layer *p_layer) {
  /// Insert layer application and runs its configuration function
  m_layerStack.pushLayer(p_layer);
  p_layer->onAttach();
}

/// Remove layer from application, the layers is only destroyed if nothing else
/// is holding it - Is a shared_ptr
void Application::popLayer(Layer *p_layer) { m_layerStack.popLayer(p_layer); }

/// Insert overlay into the application
void Application::pushOverlay(Layer *p_layer) {
  m_layerStack.pushOverlay(p_layer);
  p_layer->onAttach();
}

/// Remove overlay pointer from the application - layer only destroyed if
/// nothing holds the pointer - shared_ptr
void Application::popOverlay(Layer *p_layer) {
  m_layerStack.popOverlay(p_layer);
}

Window &Application::getWindow() { return *m_window; }

Application &Application::getApplication() { return *m_instance; }

} // namespace bez
