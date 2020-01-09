#include <stdafx.hpp>

#include <bez/Events/MouseEvent.hpp>

namespace bez {

/// Mouse Motion Event

MouseMotionEvent::MouseMotionEvent(float x, float y) {
  m_mouseCoordinates = std::make_pair(x, y);
  registerInput(std::make_pair(x, y));
};

std::string MouseMotionEvent::toString() const {
  std::stringstream ss;

  ss << "MouseMoved: [" << m_mouseCoordinates.first << " : "
     << m_mouseCoordinates.second << "]";

  return ss.str();
}

void MouseMotionEvent::registerInput(std::pair<float, float> p_mousePosition) {
  Input::registerMousePosition(p_mousePosition);
}

/// Mouse Button Event

MouseButtonEvent::MouseButtonEvent(MouseButton p_button) {
  m_button = p_button;
}

/// Mouse Button Pressed Event

MouseButtonPressedEvent::MouseButtonPressedEvent(MouseButton p_button)
    : MouseButtonEvent(p_button) {
  registerInput(p_button);
}

std::string MouseButtonPressedEvent::toString() const {
  std::stringstream ss;
  ss << "MouseButtonPressed: " << m_button;
  return ss.str();
}

void MouseButtonPressedEvent::registerInput(MouseButton p_button) {
  Input::registerMouseButton(p_button, true);
}

/// Mouse Button Release Event

MouseButtonReleasedEvent::MouseButtonReleasedEvent(MouseButton p_button)
    : MouseButtonEvent(p_button) {
  registerInput(p_button);
}

std::string MouseButtonReleasedEvent::toString() const {
  std::stringstream ss;
  ss << "MouseButtonReleased: " << m_button;
  return ss.str();
}

void MouseButtonReleasedEvent::registerInput(MouseButton p_button) {
  Input::registerMouseButton(p_button, false);
}

/// Mouse Wheel Event

MouseWheelEvent::MouseWheelEvent(std::pair<int, int> p_direction) {
  m_direction = p_direction;
}

std::pair<int, int> MouseWheelEvent::getDirection() { return m_direction; }

std::string MouseWheelEvent::toString() const {
  std::stringstream ss;

  ss << "MouseWheelEvent - [x, y] = [" << m_direction.first << ", "
     << m_direction.second << "]";

  return ss.str();
}

} // namespace bez