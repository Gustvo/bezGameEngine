#include "Mesh.hpp"

#include <GL/glew.h>
#include <SDL2/SDL.h>

namespace bez {

Mesh::Mesh() {}

Mesh::Mesh(const std::vector<float> &p_vertices,
           const std::vector<unsigned int> &p_indices) {
  m_vertices = p_vertices;
  m_indices = p_indices;

  glGenVertexArrays(1, &m_vao);
  glGenBuffers(1, &m_vbo);
  glGenBuffers(1, &m_ebo);

  bindVAO();
  bindVBO();

  glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float),
               m_vertices.data(), GL_STATIC_DRAW);

  // Element Array (Index Info)
  bindEBO();
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, p_indices.size() * sizeof(unsigned int),
               p_indices.data(), GL_STATIC_DRAW);

  // Vertex Info
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  // Color Info
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                        (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  unbindVAO();
}

void Mesh::loadData(const std::vector<float> &p_vertices,
                    const std::vector<unsigned int> &p_indices) {
  m_vertices = p_vertices;
  m_indices = p_indices;

  glGenVertexArrays(1, &m_vao);
  glGenBuffers(1, &m_vbo);
  glGenBuffers(1, &m_ebo);

  bindVAO();
  bindVBO();

  glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float),
               m_vertices.data(), GL_STATIC_DRAW);

  // Element Array (Index Info)
  bindEBO();
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, p_indices.size() * sizeof(unsigned int),
               p_indices.data(), GL_STATIC_DRAW);

  // Vertex Info
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  // Color Info
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                        (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  unbindVAO();
}

Mesh::~Mesh() {
  // dtor
}

void Mesh::draw() const {
  bindVAO();
  // glUniformMatrix4fv(m_uniformLocation, 1, GL_FALSE,
  // glm::value_ptr(getTransform())); glUniformMatrix4fv(m)
  // setUniform("transform", getTransform());

  for (std::shared_ptr<Shader> shader : m_shaders) {
    shader->useProgram();
    shader->setUniform("model", getTransform());
    glDrawElements(GL_TRIANGLES, getIndiceCount(), GL_UNSIGNED_INT, 0);
  }

  // glDrawElements(GL_TRIANGLES, getIndiceCount(), GL_UNSIGNED_INT, 0);

  unbindVAO();
}

void Mesh::bindVBO() const { glBindBuffer(GL_ARRAY_BUFFER, m_vbo); }

void Mesh::bindVAO() const { glBindVertexArray(m_vao); }

void Mesh::bindEBO() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo); }

void Mesh::unbindVAO() const { glBindVertexArray(0); }

unsigned int Mesh::getVerticeCount() const { return m_vertices.size(); }

unsigned int Mesh::getIndiceCount() const { return m_indices.size(); }

void Mesh::addShader(std::shared_ptr<Shader> p_shaderPtr) {
  m_shaders.push_back(p_shaderPtr);
}

} // namespace bez
