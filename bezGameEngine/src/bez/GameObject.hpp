#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <memory>
#include <vector>

#include <bez/Transformable.hpp>

namespace bez {

class GameObject : public Transformable {
public:
  GameObject() = default;
  ~GameObject();
  void addComponent(std::shared_ptr<GameObject> child);
  void removeComponent(std::shared_ptr<GameObject> child);

protected:
private:
  std::vector<std::shared_ptr<GameObject>> m_components;
};

} // namespace bez

#endif // GAMEOBJECT_HPP
