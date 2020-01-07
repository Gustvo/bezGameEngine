#include <stdafx.hpp>

#include "SdlWindow.hpp"

#include <GL/glew.h>

#include <bez/Events/KeyEvent.hpp>
#include <bez/Events/MouseEvent.hpp>
#include <bez/Events/WindowEvent.hpp>
#include <bez/Logger/Log.hpp>

namespace bez {

std::unique_ptr<Window> Window::create(const char *p_title,
                                       unsigned int p_width,
                                       unsigned int p_heigth) {

  return std::make_unique<SdlWindow>(p_title, p_width, p_heigth);
}

SdlWindow::SdlWindow(const char *p_title, unsigned int p_width,
                     unsigned int p_heigth) {
  init(p_title, p_width, p_heigth);
}

SdlWindow::~SdlWindow() {
  SDL_GL_DeleteContext(m_context);
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}

void SdlWindow::init(const char *p_title, unsigned int p_width,
                     unsigned int p_heigth) {
  m_isReady = false;

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    BEZ_CORE_CRIT("Failed to load SDL - %s", SDL_GetError());
    return;
  }

  m_window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, p_width, p_heigth,
                              SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);

  if (m_window == nullptr) {
    BEZ_CORE_CRIT("Failed to create window -", SDL_GetError());
    return;
  } else
    glViewport(0, 0, p_width, p_heigth);

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

  m_context = SDL_GL_CreateContext(m_window);

  if (glewInit() != GLEW_OK) {
    BEZ_CORE_CRIT("Failed to initialize GLEW -", SDL_GetError());
    return;
  }

  WINDOW_WIDTH = p_width;
  WINDOW_HEIGTH = p_heigth;

  m_isReady = true;
}

void SdlWindow::onUpdate() {
  // Create and send to callback function all events casted as `bez events`
  SDL_Event e;
  while (SDL_PollEvent(&e)) {

    switch (e.type) {

    case SDL_QUIT: {
      WindowClosedEvent event;
      m_eventCallback(event);
      break;
    }

    case SDL_KEYDOWN: {
      KeyPressedEvent event(static_cast<Keycode>(e.key.keysym.scancode));
      m_eventCallback(event);
      break;
    }

    case SDL_KEYUP: {
      KeyReleasedEvent event(static_cast<Keycode>(e.key.keysym.scancode));
      m_eventCallback(event);
      break;
    }

    case SDL_MOUSEMOTION: {
      MouseMotionEvent event(e.motion.x, e.motion.y);
      m_eventCallback(event);
      break;
    }

    case SDL_WINDOWEVENT: {
      switch (e.window.event) {
      case SDL_WINDOWEVENT_RESIZED: {
        WindowResizedEvent event(e.window.data1, e.window.data2);
        m_eventCallback(event);
        break;
      }
      }
      break;
    }
    }
  }
}

void SdlWindow::render() { SDL_GL_SwapWindow(m_window); }

void SdlWindow::setEventCallback(const std::function<void(Event &)> &callback) {
  m_eventCallback = callback;
}

void SdlWindow::resize(unsigned int width, unsigned int heigth) {
  WINDOW_WIDTH = width;
  WINDOW_HEIGTH = heigth;

  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGTH);
}

void SdlWindow::resize(std::pair<unsigned int, unsigned int> windowSize) {
  auto [x, y] = windowSize;
  WINDOW_WIDTH = x;
  WINDOW_HEIGTH = y;

  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGTH);
}

void SdlWindow::clear() {
  glClearColor(.5f, .5f, .5f, .5f);
  glClear(GL_COLOR_BUFFER_BIT);
}

} // namespace bez
