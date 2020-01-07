#include <stdafx.hpp>

#include <bez/Layer.hpp>

namespace bez {

Layer::Layer(const std::string &p_name)
    : m_active(true), m_visible(true), m_name(p_name) {}

void Layer::onAttach() {}

void Layer::onDetach() {}

void Layer::onUpdate() {}

void Layer::onEvent(Event &p_event) {}

const std::string &Layer::getName() { return m_name; }

} // namespace bez
