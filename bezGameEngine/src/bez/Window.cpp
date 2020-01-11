#include <stdafx.hpp>

#include "Window.hpp"

namespace bez {

void Window::draw(const Drawable &p_drawable) { p_drawable.draw(); }

glm::vec<2, unsigned int> Window::getWindowSize() const {
  return glm::vec2((float)WINDOW_WIDTH, (float)WINDOW_HEIGTH);
}

bool Window::isReady() { return m_isReady; }

} // namespace bez
