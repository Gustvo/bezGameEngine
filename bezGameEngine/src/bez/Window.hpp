#ifndef DISPLAY_H
#define DISPLAY_H

#include <glm/glm.hpp>
#include <iostream>
#include <memory>

#include <Drawable.hpp>
#include <bez/Events/Event.hpp>

namespace bez {
class Window {
public:
  // Window(){};
  virtual ~Window() = default;
  void draw(const Drawable &drawable);

  glm::vec<2, unsigned int> getWindowSize() const;

  virtual void clear() = 0;
  bool isReady();
  virtual void onUpdate() = 0;
  virtual void render() = 0;
  virtual void resize(unsigned int width, unsigned int heigth) = 0;
  virtual void resize(std::pair<unsigned int, unsigned int>) = 0;

  static std::unique_ptr<Window>
  create(const char *p_title, unsigned int p_width, unsigned int p_heigth);

  virtual void
  setEventCallback(const std::function<void(Event &)> &callback) = 0;

protected:
  bool m_isReady;
  unsigned int WINDOW_WIDTH;
  unsigned int WINDOW_HEIGTH;

private:
};

} // namespace bez
#endif // DISPLAY_H
