#ifndef LAYER_H
#define LAYER_H

#include <bez/Events/Event.hpp>

namespace bez {
class Layer {
public:
  Layer(const std::string &layerName);
  virtual ~Layer() = default;

  /// Initial configuration of the layeR
  virtual void onAttach();

  /// to run when layer is removed from layerstack
  virtual void onDetach();
  virtual void onUpdate();

  /// Handle events passed down from the application layer
  virtual void onEvent(Event &event);

  inline bool isActive() { return m_active; };
  inline bool isVisible() { return m_visible; };

  const std::string &getName();

protected:
  bool m_active;
  bool m_visible;

  std::string m_name;

private:
};

} // namespace bez
#endif // LAYER_H
