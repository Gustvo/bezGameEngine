#ifndef SDLWINDOW_HPP
#define SDLWINDOW_HPP

#include <SDL2/SDL.h>
#include <bez/Window.hpp>

namespace bez {
class SdlWindow : public Window {
public:
  SdlWindow(const char *p_title, unsigned int p_width, unsigned int p_heigth);
  virtual ~SdlWindow();

  void init(const char *p_title, unsigned int p_width, unsigned int p_heigth);
  void render() override;
  void clear() override;
  void resize(unsigned int width, unsigned int heigth) override;
  void resize(std::pair<unsigned int, unsigned int> windowSize) override;

  void setEventCallback(const std::function<void(Event &)> &callback) override;
  void onUpdate() override;

protected:
private:
  SDL_Window *m_window;
  SDL_GLContext m_context;

  std::function<void(Event &)> m_eventCallback;
};
} // namespace bez

#endif // SDLWINDOW_HPP
