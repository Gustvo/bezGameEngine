#include <stdafx.hpp>

#include "LayerStack.hpp"

namespace bez {

LayerStack::LayerStack() {
  // ctor
	m_layerCount = 0;
}

LayerStack::~LayerStack() { m_layers.clear(); }

void LayerStack::pushLayer(Layer *p_layer) {
  m_layers.insert(m_layers.begin() + m_layerCount++, p_layer);
  p_layer->onAttach();
}

void LayerStack::pushOverlay(Layer *p_layer) {
  m_layers.push_back(p_layer);
  p_layer->onAttach();
}

void LayerStack::popLayer(Layer *p_layer) {
  auto it = std::find(m_layers.begin(), m_layers.begin() + m_layerCount, p_layer);

  if (it != m_layers.end()) {
    (*it)->onDetach();
    m_layers.erase(it);
    m_layerCount--;
  }
}

void LayerStack::popOverlay(Layer *p_overlay) {
  auto it = std::find(m_layers.begin(), m_layers.end(), p_overlay);

  if (it != m_layers.end()) {
    (*it)->onDetach();
    m_layers.erase(it);
  }
}

} // namespace bez
