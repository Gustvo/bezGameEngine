#include <stdafx.hpp>

#include <bez/GameObject.hpp>

namespace bez {

GameObject::~GameObject() {}

void GameObject::addComponent(std::shared_ptr<GameObject> child) {
  m_components.push_back(std::move(child));
}

void GameObject::removeComponent(std::shared_ptr<GameObject> child) {
  auto it = std::find(m_components.begin(), m_components.end(), child);
  if (it != m_components.end()) {
    m_components.erase(it);
  }
}

} // namespace bez
