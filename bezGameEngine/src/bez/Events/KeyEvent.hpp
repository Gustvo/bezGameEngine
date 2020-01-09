#ifndef KEYEVENT_HPP
#define KEYEVENT_HPP

#include <bez/Events/Event.hpp>
#include <bez/Input.hpp>
#include <bez/Keycodes.hpp>

namespace bez {

/**
 * \brief Class for encapsulating all keyboard events.
 *
 * Register all keystrokes in a Input buffer.
 */
class KeyEvent : public Event {
public:
  inline Keycode getKeyCode() { return m_keycode; };

protected:
  KeyEvent(Keycode keycode) { m_keycode = keycode; };
  virtual ~KeyEvent(){};

  /// Test Doc
  Keycode m_keycode;

  virtual void registerKey(Keycode key) const = 0;

private:
};

class KeyPressedEvent : public KeyEvent {
public:
  KeyPressedEvent(Keycode keycode) : KeyEvent(keycode) {
    registerKey(keycode);
  };

  static EventType getStaticType() { return EventType::KEYDOWN; };
  EventType getEventType() const override { return getStaticType(); };

  std::string toString() const override {
    std::stringstream ss;
    ss << "KeyPressed: " << m_keycode;
    return ss.str();
  }

protected:
private:
  /// Registers the keypress to the Input buffer
  void registerKey(Keycode key) const override {
    Input::registerKey(key, true);
  };
};

class KeyReleasedEvent : public KeyEvent {
public:
  KeyReleasedEvent(Keycode keycode) : KeyEvent(keycode) {
    registerKey(keycode);
  };

  static EventType getStaticType() { return EventType::KEYUP; };
  EventType getEventType() const override { return getStaticType(); };

  std::string toString() const override {
    std::stringstream ss;
    ss << "KeyReleased: " << m_keycode;
    return ss.str();
  }

protected:
private:
  /// Registers the keyrelease to the Input buffer
  void registerKey(Keycode key) const override {
    Input::registerKey(key, false);
  };
};

class TextInputEvent : public KeyEvent {
public:
  TextInputEvent(Keycode keycode) : KeyEvent(keycode){};

  static EventType getStaticType() { return EventType::TEXTINPUT; };
  EventType getEventType() const override { return getStaticType(); };

  std::string toString() const override {
    std::stringstream ss;
    ss << "TextInput: " << m_keycode;
    return ss.str();
  }

protected:
  inline void registerKey(Keycode) const override{};
};

} // namespace bez

#endif // KEYEVENT_HPP
