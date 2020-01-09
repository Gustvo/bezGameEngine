#ifndef IMGUILAYER_HPP
#define IMGUILAYER_HPP

#include <bez/Events/MouseEvent.hpp>
#include <bez/Layer.hpp>

namespace bez {

class ImGuiLayer : public Layer {
public:
  ImGuiLayer();
  ~ImGuiLayer() = default;

  void onAttach() override;
  void onDetach() override;
  void onUpdate() override;
  void onEvent(Event &) override;

protected:
private:
  bool handleKeyInput(KeyEvent &);
  bool handleMouseInput(MouseButtonEvent &);
  bool handleMouseMotion(MouseMotionEvent &);

  bool m_mouseBuffer[BEZ_NUM_MOUSEBUTTONS];
  double m_time;
};

} // namespace bez

#endif // IMGUILAYER_HPP
