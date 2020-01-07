#ifndef ENTITY_H
#define ENTITY_H

#include <glm/glm.hpp>

namespace bez {

class Transformable {
public:
  Transformable();
  virtual ~Transformable() = default;

  virtual void move(glm::vec3 Direction);
  virtual void move(float x, float y, float z);

  virtual void setPosition(glm::vec3 Position);
  virtual void setPosition(float x, float y, float z);

  void setScale(glm::vec3 Scale);
  void setScale(float Scale);
  void setScale(float x, float y, float z);

  void rotate(glm::vec3 angle);
  void rotateX(float angle);
  void rotateY(float angle);
  void rotateZ(float angle);

  virtual glm::vec3 getPosition() const;
  virtual float getPositionX() const;
  virtual float getPositionY() const;
  virtual float getPositionZ() const;

  virtual glm::vec3 getRotation() const;
  virtual float getRotationX() const;
  virtual float getRotationY() const;
  virtual float getRotationZ() const;

  virtual glm::vec3 getScale() const;
  virtual float getScaleX() const;
  virtual float getScaleY() const;
  virtual float getScaleZ() const;

protected:
  glm::mat4 getTransform() const;

private:
  glm::vec3 m_position;
  glm::vec3 m_rotation;
  glm::vec3 m_scale;
};

} // namespace bez

#endif // ENTITY_H
