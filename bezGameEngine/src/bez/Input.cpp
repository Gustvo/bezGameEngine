#include <bez/Input.hpp>

#include <bez/Logger/Log.hpp>

namespace bez {

Input *Input::m_input = nullptr;

Input::Input() {

  if (m_input != nullptr)
    delete m_input;
    
  BEZ_CORE_WARN("CREATING INPUT INTERFACE");
  m_input = this;
  for (int i = 0; i < BEZ_NUM_KEYCODES; ++i) {
    m_keyStates[i] = false;
    m_prevKeyStates[i] = false;
  }

  for (auto &button : m_mouseButtonStates)
    button = false;

  m_mouseCoordinates = std::make_pair(0.f, 0.f);
}

Input::~Input() {
  BEZ_CORE_WARN("DELETING INPUT INTERFACE");
  m_input = nullptr;
}

bool Input::isKeyPressed(Keycode key) { return m_input->m_keyStates[key]; }

bool Input::isKeyRepeated(Keycode key) {
  return m_input->m_keyStates[key] == m_input->m_prevKeyStates[key] &&
         m_input->m_keyStates[key] == true;
}

bool Input::isMousePressed(MouseButton button) {
  return m_input->m_mouseButtonStates[button];
}

void Input::registerMousePosition(std::pair<float, float> p_mousePosition) {
  m_input->m_mouseCoordinates = p_mousePosition;
}

void Input::registerKey(Keycode key, bool p_keyState) {
  std::copy(m_input->m_keyStates, m_input->m_keyStates + BEZ_NUM_KEYCODES,
            m_input->m_prevKeyStates);
  m_input->m_keyStates[key] = p_keyState;
}

std::pair<float, float> Input::getMousePosition() {
  return m_input->m_mouseCoordinates;
}

void Input::registerMouseButton(MouseButton button, bool state) {
  m_input->m_mouseButtonStates[button] = state;
}

} // namespace bez
