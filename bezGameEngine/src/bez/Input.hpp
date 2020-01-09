#ifndef INPUT_HPP
#define INPUT_HPP

#include <memory>
#include <utility>

#include <bez/Keycodes.hpp>
#include <bez/MouseCodes.hpp>

namespace bez {

class Input {
public:
  Input();
  ~Input();

  /// Returns if the key is being pressed
  static bool isKeyPressed(Keycode key);

  /// Returns if the key is being pressed for multiple frames
  static bool isKeyRepeated(Keycode key);

  /// Returns if mouse button is being pressed
  static bool isMousePressed(MouseButton button);

  static std::pair<float, float> getMousePosition();

  //static bool *getAllKeys();

protected:
  // virtual bool isKeyPressedImpl(Keycode key) = 0;

private:

  static Input *m_input;

  /**
   * \brief Registers key press in the input buffer
   *
   * To be called on creation of classes that inherit from KeyEvent
   */
  static void registerKey(Keycode key, bool keyState);

  /**
   * \brief Registers mouse button press in the input buffer
   *
   * To be called on MouseButtonPressedEvent and MouseButtonPressedEvent
   * creation
   */
  static void registerMouseButton(MouseButton button, bool state);

  /**
   * \brief Registers mouse position in the input buffer
   *
   * To be called on MouseMotionEvent creation
   */
  static void registerMousePosition(std::pair<float, float> mousePosition);

  bool m_keyStates[BEZ_NUM_KEYCODES];
  bool m_prevKeyStates[BEZ_NUM_KEYCODES];

  bool m_mouseButtonStates[BEZ_NUM_MOUSEBUTTONS];

  std::pair<float, float> m_mouseCoordinates;

  friend class KeyPressedEvent;
  friend class KeyReleasedEvent;
  friend class MouseMotionEvent;
  friend class MouseButtonPressedEvent;
  friend class MouseButtonReleasedEvent;
};


} // namespace bez

#endif // INPUT_HPP
