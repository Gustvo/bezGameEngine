#ifndef MOUSEEVENT_HPP
#define MOUSEEVENT_HPP

#include <sstream>
#include <utility>

#include <bez/Events/Event.hpp>
#include <bez/Input.hpp>
#include <bez/MouseCodes.hpp>

namespace bez {

class MouseButtonEvent : public Event {
public:
  inline MouseButton getMouseButton() { return m_button; }

protected:
  MouseButtonEvent(MouseButton);
  MouseButton m_button;
  virtual void registerInput(MouseButton) = 0;

private:
};

class MouseMotionEvent : public Event {
public:
  MouseMotionEvent(float x, float y);

  /// String representation of MouseMotionEvent
  std::string toString() const override;

  static EventType getStaticType() { return EventType::MOUSEMOTION; };
  EventType getEventType() const override { return EventType::MOUSEMOTION; }

  inline float getX() { return m_mouseCoordinates.first; };
  inline float getY() { return m_mouseCoordinates.second; };

protected:
private:
  std::pair<float, float> m_mouseCoordinates;

  void registerInput(std::pair<float, float> p_mousePosition);
};

class MouseButtonPressedEvent : public MouseButtonEvent {
public:
  MouseButtonPressedEvent(MouseButton button);

  /// String representation of MouseButtonPressedEvent
  std::string toString() const override;

  static EventType getStaticType() { return EventType::MOUSEBUTTONDOWN; };
  EventType getEventType() const override { return getStaticType(); };

protected:
private:
  void registerInput(MouseButton button) override;
};

class MouseButtonReleasedEvent : public MouseButtonEvent {
public:
  MouseButtonReleasedEvent(MouseButton button);

  /// String representation of MouseButtonPressedEvent
  std::string toString() const override;

  static EventType getStaticType() { return EventType::MOUSEBUTTONDOWN; };
  EventType getEventType() const override { return getStaticType(); };

protected:
private:
  void registerInput(MouseButton button) override;
};

class MouseWheelEvent : public Event {
public:
  MouseWheelEvent(std::pair<int, int> ScrollDirection);

  static EventType getStaticType() { return EventType::MOUSEWHEEL; };
  EventType getEventType() const override { return getStaticType(); };

  std::pair<int,int> getDirection();

  std::string toString() const override;

protected:
private:
  std::pair<int, int> m_direction;
};

} // namespace bez

#endif // MOUSEEVENT_HPP
