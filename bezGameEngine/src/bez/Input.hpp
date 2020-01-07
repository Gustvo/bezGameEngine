#ifndef INPUT_HPP
#define INPUT_HPP

#include <memory>
#include <utility>

#include <bez/Keycodes.hpp>
#include <bez/MouseCodes.hpp>

namespace bez {

class Input {
public:
  Input() = default;

  static bool isKeyPressed(Keycode key) { return m_input->m_keyStates[key]; };
  static bool isKeyRepeated(Keycode key) {
    return m_input->m_keyStates[key] == m_input->m_prevKeyStates[key] &&
           m_input->m_keyStates[key] == true;
  };
  static bool isMousePressed(MouseButton button) {
    return m_mouseButtonStates[button];
  };

  static void registerKey(Keycode key, bool keyState) {
    std::copy(m_keyStates, m_keyStates + BEZ_NUM_KEYCODES,
              m_input->m_prevKeyStates);
    m_input->m_keyStates[key] = keyState;
  };

  static void registerMousePosition(std::pair<float, float> mousePosition) {
    m_mouseCoordinates = mousePosition;
  };

  static std::pair<float, float> getMousePosition() {
    return m_mouseCoordinates;
  };

  static void registerMouseButton(MouseButton button, bool state) {
    m_mouseButtonStates[button] = state;
  };

protected:
  // virtual bool isKeyPressedImpl(Keycode key) = 0;

private:
  inline static std::unique_ptr<Input> m_input = std::make_unique<Input>();
  inline static bool m_keyStates[BEZ_NUM_KEYCODES] = {};
  inline static bool m_prevKeyStates[BEZ_NUM_KEYCODES] = {};

  inline static bool m_mouseButtonStates[BEZ_NUM_MOUSEBUTTONS] = {};

  inline static std::pair<float, float> m_mouseCoordinates =
      std::make_pair(0.f, 0.f);

  friend class KeyPressedEvent;
  friend class KeyReleasedEvent;
  friend class MouseMotionEvent;
  friend class MouseButtonPressedEvent;
  friend class MouseButtonReleasedEvent;
};

// std::unique_ptr<Input> Input::m_input = std::make_unique<Input>();
// bool Input::m_keyStates[BEZ_NUM_KEYCODES] = {0};

} // namespace bez

#endif // INPUT_HPP
