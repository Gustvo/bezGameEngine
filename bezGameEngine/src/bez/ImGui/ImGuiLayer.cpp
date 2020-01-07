#include <stdafx.hpp>

#include <Platform/OpenGL/imgui_impl_opengl3.hpp>
#include <SDL2/SDL.h>
#include <bez/Application.hpp>
#include <bez/ImGui/ImGuiLayer.hpp>
#include <bez/Keycodes.hpp>
#include <imgui.h>

namespace bez {

ImGuiLayer::ImGuiLayer()
    : Layer("ImGuiLayer"), m_time(0.0f) {}

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

}

void ImGuiLayer::onDetach() {}

void ImGuiLayer::onUpdate() {
  ImGuiIO &io = ImGui::GetIO();

  Application &app = Application::getApplication();
  io.DisplaySize = ImVec2((float)app.getWindow().getWindowSize().x, (float)app.getWindow().getWindowSize().y);

  double time = SDL_GetTicks()/1000;

  io.DeltaTime = m_time > 0.0f ? (time - m_time == 0? (1.f/60.f) : time - m_time) : (1.f / 60.f);
  m_time = time;

  ImGui_ImplOpenGL3_NewFrame();
  ImGui::NewFrame();

  static bool show = true;

  ImGui::ShowDemoWindow(&show);

  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiLayer::onEvent(Event &p_event) {}

} // namespace bez
