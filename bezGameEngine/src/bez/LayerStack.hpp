#ifndef LAYERSTACK_H
#define LAYERSTACK_H

#include <vector>

#include <bez/Layer.hpp>

namespace bez {

class LayerStack {
public:
  LayerStack();
  virtual ~LayerStack();

  /// Insert laayer into the layerstack
  void pushLayer(Layer *);

  /// Insert overlay into the layerstack
  void pushOverlay(Layer *);

  /// Remove layer from the layerstack
  void popLayer(Layer *);

  /// Remove overlay from the layerstack
  void popOverlay(Layer *);

  /// How many layers this layerstack holds
  inline unsigned int size() { return m_layers.size(); };

  // Iterator implementation - loops every layer owned by the layerstack

  std::vector<Layer *>::iterator begin() {
    return m_layers.begin();
  };

  std::vector<Layer *>::iterator end() {
    return m_layers.end();
  };

  std::vector<Layer *>::reverse_iterator rbegin() {
    return m_layers.rbegin();
  };

  std::vector<Layer *>::reverse_iterator rend() {
    return m_layers.rend();
  };

protected:
private:
  std::vector<Layer *> m_layers;
  unsigned int m_layerCount; // Iterator pointing to the last layer in the layerstack
                       // - separates layers from overlays
};

} // namespace bez

#endif // LAYERSTACK_H
