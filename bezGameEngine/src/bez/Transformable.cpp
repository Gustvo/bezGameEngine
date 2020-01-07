#include <stdafx.hpp>

#include "Transformable.hpp"
#include <glm/gtc/matrix_transform.hpp>

namespace bez {

Transformable::Transformable()
    : m_position(glm::vec3(0.f, 0.f, 0.f)),
      m_rotation(glm::vec3(0.f, 0.f, 0.f)), m_scale(glm::vec3(1.f, 1.f, 1.f)) {}

void Transformable::move(glm::vec3 p_direction) { m_position += p_direction; }

void Transformable::move(float p_x, float p_y, float p_z) {
  m_position += glm::vec3(p_x, p_y, p_z);
}

void Transformable::setPosition(float p_x, float p_y, float p_z) {
  m_position = glm::vec3(p_x, p_y, p_z);
}

void Transformable::setPosition(glm::vec3 p_pos) { m_position = p_pos; }

void Transformable::rotateX(float p_angle) { m_rotation.x += p_angle; }

void Transformable::rotateY(float p_angle) { m_rotation.y += p_angle; }

void Transformable::rotateZ(float p_angle) { m_rotation.z += p_angle; }

void Transformable::rotate(glm::vec3 p_angle) { m_rotation += p_angle; }

glm::vec3 Transformable::getPosition() const { return m_position; }

float Transformable::getPositionX() const { return m_position.x; }

float Transformable::getPositionY() const { return m_position.y; }

float Transformable::getPositionZ() const { return m_position.z; }

glm::vec3 Transformable::getRotation() const { return m_rotation; }

float Transformable::getRotationX() const { return m_rotation.x; }

float Transformable::getRotationY() const { return m_rotation.y; }

float Transformable::getRotationZ() const { return m_rotation.z; }

void Transformable::setScale(glm::vec3 p_scale) { m_scale = p_scale; }

void Transformable::setScale(float p_scale) {
  m_scale = glm::vec3(p_scale, p_scale, p_scale);
}

void Transformable::setScale(float p_x, float p_y, float p_z) {
  m_scale = glm::vec3(p_x, p_y, p_z);
}

glm::vec3 Transformable::getScale() const { return m_scale; }

float Transformable::getScaleX() const { return m_scale.x; }

float Transformable::getScaleY() const { return m_scale.y; }

float Transformable::getScaleZ() const { return m_scale.z; }

glm::mat4 Transformable::getTransform() const {
  // Returns a transformation matrix that is necessary to pass to the Shader
  glm::mat4 model(1.f);
  model = glm::translate(model, m_position); // Apply translation first
  model =
      glm::rotate(model, glm::radians(m_rotation.z), glm::vec3(0.f, 0.f, 1.f));
  model =
      glm::rotate(model, glm::radians(m_rotation.y), glm::vec3(0.f, 1.f, 0.f));
  model =
      glm::rotate(model, glm::radians(m_rotation.x), glm::vec3(1.f, 0.f, 0.f));
  model = glm::scale(model, m_scale);
  return model;
}

} // namespace bez
