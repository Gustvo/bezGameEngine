#ifndef WINDOWEVENT_HPP
#define WINDOWEVENT_HPP

#include <sstream>
#include <utility>

#include <bez/Events/Event.hpp>

namespace bez {

class WindowClosedEvent : public Event {
public:
  WindowClosedEvent() = default;

  EventType getEventType() const override { return getStaticType(); };

  static EventType getStaticType() { return EventType::QUIT; };

  std::string toString() const override { return "WindowClosed"; };

private:
};

class WindowResizedEvent : public Event {
public:
  WindowResizedEvent(unsigned int width, unsigned int heigth) {
    m_newSize = std::make_pair(width, heigth);
  }

  EventType getEventType() const override { return getStaticType(); }

  static EventType getStaticType() { return EventType::WINDOWEVENT; }

  inline std::pair<unsigned int, unsigned int> getWindowSize() {
    return m_newSize;
  }

  inline unsigned int getWindowWidth() {
    auto [x, y] = getWindowSize();
    return x;
  }

  inline unsigned int getWindowHeigth() {
    auto [x, y] = getWindowSize();
    return y;
  }

  std::string toString() const override {
    std::stringstream ss;
    ss << "Window Resized, new size: [" << m_newSize.first << " : "
       << m_newSize.second << "]";
    return ss.str();
  }

protected:
private:
  std::pair<unsigned int, unsigned int> m_newSize;
};

} // namespace bez

#endif
