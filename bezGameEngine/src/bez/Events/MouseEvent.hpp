#ifndef MOUSEEVENT_HPP
#define MOUSEEVENT_HPP

#include <sstream>
#include <utility>

#include <bez/Events/Event.hpp>
#include <bez/Input.hpp>
#include <bez/MouseCodes.hpp>

namespace bez {

class MouseMotionEvent : public Event {
public:
  MouseMotionEvent(float x, float y) {
    m_mouseCoordinates = std::make_pair(x, y);
  };

  /// String representation of MouseMotionEvent
  std::string toString() const override {
    std::stringstream ss;

    ss << "MouseMoved: [" << m_mouseCoordinates.first << " : "
       << m_mouseCoordinates.second << "]";

    return ss.str();
  }

  static EventType getStaticType() { return EventType::MOUSEMOTION; };
  EventType getEventType() const override { return EventType::MOUSEMOTION; }

  inline float getX() { return m_mouseCoordinates.first; };
  inline float getY() { return m_mouseCoordinates.second; };

protected:
private:
  std::pair<float, float> m_mouseCoordinates;
};

class MouseButtonPressedEvent : public Event {
public:
protected:
private:
  inline void registerMouse(){};
};

} // namespace bez

#endif // MOUSEEVENT_HPP
