#ifndef APPLICATION_H
#define APPLICATION_H

#include <glm/glm.hpp>

#include <bez/Input.hpp>
#include <bez/LayerStack.hpp>
#include <bez/Logger/Log.hpp>
#include <bez/Window.hpp>

namespace bez {

class Application {
public:
  Application();
  virtual ~Application();

  virtual void init(const char *Title = "Bez Game Engine",
                    unsigned int Width = 600, unsigned int Heigth = 600);
  void run();
  void stop();

  bool isRunning();

  void onEvent(Event &e);

  void pushLayer(Layer *Layer);
  void pushOverlay(Layer *Layer);

  void popLayer(Layer *Layer);
  void popOverlay(Layer *Layer);

  Window &getWindow();

  static Application &getApplication();

protected:
private:
  std::unique_ptr<Window> m_window;
  Input *m_input;
  bool m_isRunning;
  LayerStack m_layerStack;

  static Application *s_instance;
};

// To be defined by the client
Application *CreateApplication();

} // namespace bez

#endif // APPLICATION_H
