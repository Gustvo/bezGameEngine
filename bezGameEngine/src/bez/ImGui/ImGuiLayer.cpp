#include <stdafx.hpp>

#include <Platform/OpenGL/imgui_impl_opengl3.hpp>
#include <SDL2/SDL.h>
#include <bez/Application.hpp>
#include <bez/Events/KeyEvent.hpp>
#include <bez/Events/WindowEvent.hpp>
#include <bez/ImGui/ImGuiLayer.hpp>
#include <bez/Keycodes.hpp>
#include <imgui.h>

namespace bez {

ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer"), m_time(0.0f) {
  for (auto &it : m_mouseBuffer)
    it = false;
}

void ImGuiLayer::onAttach() {
  ImGui::CreateContext();
  ImGui::StyleColorsDark();

  ImGuiIO &io = ImGui::GetIO();
  io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;

  // Keyboard mapping. ImGui will use those indices to peek into the
  // io.KeysDown[] array.
  //
  io.KeyMap[ImGuiKey_Tab] = BEZ_KEYCODE_TAB;
  io.KeyMap[ImGuiKey_LeftArrow] = BEZ_KEYCODE_LEFT;
  io.KeyMap[ImGuiKey_RightArrow] = BEZ_KEYCODE_RIGHT;
  io.KeyMap[ImGuiKey_UpArrow] = BEZ_KEYCODE_UP;
  io.KeyMap[ImGuiKey_DownArrow] = BEZ_KEYCODE_DOWN;
  io.KeyMap[ImGuiKey_PageUp] = BEZ_KEYCODE_PAGEUP;
  io.KeyMap[ImGuiKey_PageDown] = BEZ_KEYCODE_PAGEDOWN;
  io.KeyMap[ImGuiKey_Home] = BEZ_KEYCODE_HOME;
  io.KeyMap[ImGuiKey_End] = BEZ_KEYCODE_END;
  io.KeyMap[ImGuiKey_Insert] = BEZ_KEYCODE_INSERT;
  io.KeyMap[ImGuiKey_Delete] = BEZ_KEYCODE_DELETE;
  io.KeyMap[ImGuiKey_Backspace] = BEZ_KEYCODE_BACKSPACE;
  io.KeyMap[ImGuiKey_Space] = BEZ_KEYCODE_SPACE;
  io.KeyMap[ImGuiKey_Enter] = BEZ_KEYCODE_RETURN;
  io.KeyMap[ImGuiKey_Escape] = BEZ_KEYCODE_ESCAPE;
  io.KeyMap[ImGuiKey_KeyPadEnter] = BEZ_KEYCODE_RETURN2;
  io.KeyMap[ImGuiKey_A] = BEZ_KEYCODE_A;
  io.KeyMap[ImGuiKey_C] = BEZ_KEYCODE_C;
  io.KeyMap[ImGuiKey_V] = BEZ_KEYCODE_V;
  io.KeyMap[ImGuiKey_X] = BEZ_KEYCODE_X;
  io.KeyMap[ImGuiKey_Y] = BEZ_KEYCODE_Y;
  io.KeyMap[ImGuiKey_Z] = BEZ_KEYCODE_Z;

  io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

  ImGui_ImplOpenGL3_Init("#version 410 core");

  Application &app = Application::getApplication();
  io.DisplaySize = ImVec2((float)app.getWindow().getWindowSize().x,
                          (float)app.getWindow().getWindowSize().y);
}

void ImGuiLayer::onDetach() {}

void ImGuiLayer::onUpdate() {
  ImGuiIO &io = ImGui::GetIO();

  double time = SDL_GetTicks() / 1000;

  io.DeltaTime = m_time > 0.0f
                     ? (time - m_time == 0 ? (1.f / 60.f) : time - m_time)
                     : (1.f / 60.f);
  m_time = time;

  io.MouseDown[0] = m_mouseBuffer[0] || Input::isMousePressed(BEZ_BUTTON_LEFT);
  io.MouseDown[1] = m_mouseBuffer[1] || Input::isMousePressed(BEZ_BUTTON_RIGHT);
  io.MouseDown[2] =
      m_mouseBuffer[2] || Input::isMousePressed(BEZ_BUTTON_MIDDLE);

  for (auto &button : m_mouseBuffer)
    button = false;

  ImGui_ImplOpenGL3_NewFrame();
  ImGui::NewFrame();
    if (m_visible)
      ImGui::ShowDemoWindow(&m_visible);

  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiLayer::onEvent(Event &p_event) {
  ImGuiIO &io = ImGui::GetIO();

  EventDispatcher dispatcher(p_event);

  dispatcher.dispatch<KeyPressedEvent>(
      std::bind(&ImGuiLayer::handleKeyInput, this, std::placeholders::_1));

  dispatcher.dispatch<KeyReleasedEvent>(
      std::bind(&ImGuiLayer::handleKeyInput, this, std::placeholders::_1));

  dispatcher.dispatch<MouseButtonPressedEvent>(
      std::bind(&ImGuiLayer::handleMouseInput, this, std::placeholders::_1));

  dispatcher.dispatch<MouseButtonReleasedEvent>(
      std::bind(&ImGuiLayer::handleMouseInput, this, std::placeholders::_1));

  dispatcher.dispatch<MouseMotionEvent>(
      std::bind(&ImGuiLayer::handleMouseMotion, this, std::placeholders::_1));

  dispatcher.dispatch<MouseWheelEvent>(std::bind(
      [&io](MouseWheelEvent &p_event) {
        if (p_event.getDirection().first > 0)
          io.MouseWheelH += 1;
        if (p_event.getDirection().first < 0)
          io.MouseWheelH -= 1;
        if (p_event.getDirection().second > 0)
          io.MouseWheel += 1;
        if (p_event.getDirection().second < 0)
          io.MouseWheel -= 1;
        return false;
      },
      std::placeholders::_1));

  dispatcher.dispatch<TextInputEvent>(std::bind(
      [&io](TextInputEvent &p_event) {
        int keycode = p_event.getKeyCode();
        io.AddInputCharacter(keycode);
        return io.WantTextInput;
      },
      std::placeholders::_1));

  dispatcher.dispatch<WindowResizedEvent>(std::bind(
      [&io](WindowResizedEvent &p_event) {
        Application &app = Application::getApplication();
        io.DisplaySize = ImVec2((float)app.getWindow().getWindowSize().x,
                                (float)app.getWindow().getWindowSize().y);

        return false;
      },
      std::placeholders::_1));
}

bool ImGuiLayer::handleKeyInput(KeyEvent &p_event) {

  ImGuiIO &io = ImGui::GetIO();

  int key = p_event.getKeyCode();

  if (Input::isKeyPressed(BEZ_KEYCODE_ESCAPE))
    m_visible = !m_visible;

  io.KeysDown[key] = Input::isKeyPressed(static_cast<Keycode>(key));
  io.KeyShift = Input::isKeyPressed(BEZ_KEYCODE_LSHIFT) ||
                Input::isKeyPressed(BEZ_KEYCODE_RSHIFT);

  io.KeyCtrl = Input::isKeyPressed(BEZ_KEYCODE_LCTRL) ||
               Input::isKeyPressed(BEZ_KEYCODE_RCTRL);

  io.KeyAlt = Input::isKeyPressed(BEZ_KEYCODE_LALT);

  io.KeySuper = Input::isKeyPressed(BEZ_KEYCODE_LSUPER);

  return io.WantCaptureKeyboard;;
}

bool ImGuiLayer::handleMouseInput(MouseButtonEvent &p_event) {

  if (p_event.getMouseButton() == BEZ_BUTTON_LEFT)
    m_mouseBuffer[0] = true;
  if (p_event.getMouseButton() == BEZ_BUTTON_RIGHT)
    m_mouseBuffer[1] = true;
  if (p_event.getMouseButton() == BEZ_BUTTON_MIDDLE)
    m_mouseBuffer[2] = true;
  return ImGui::GetIO().WantCaptureMouse;
}

bool ImGuiLayer::handleMouseMotion(MouseMotionEvent &p_event) {
  ImGuiIO &io = ImGui::GetIO();

  auto [mousex, mousey] = Input::getMousePosition();
  io.MousePos = ImVec2(mousex, mousey);

  return false;
}

} // namespace bez
