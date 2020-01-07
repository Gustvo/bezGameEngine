#ifndef MESH_H
#define MESH_H

#include <Drawable.hpp>
#include <ResourceAllocator.hpp>
#include <bez/GameObject.hpp>
#include <bez/Shader.hpp>

namespace bez {

class Mesh : public Transformable, public Drawable {
public:
  Mesh(const std::vector<float> &Vertices,
       const std::vector<unsigned int> &p_indices);
  Mesh();
  virtual ~Mesh();

  virtual void draw() const override;

  void loadData(const std::vector<float> &Vertices,
                const std::vector<unsigned int> &p_indices);

  void addShader(std::shared_ptr<Shader> Shader_ptr);

protected:
private:
  std::vector<float> m_vertices;
  std::vector<unsigned int> m_indices;
  unsigned int m_vbo;
  unsigned int m_vao;
  unsigned int m_ebo;
  unsigned int m_uniformLocation;

  void bindEBO() const;
  void bindVAO() const;
  void bindVBO() const;

  void unbindVAO() const;

  unsigned int getVerticeCount() const;
  unsigned int getIndiceCount() const;

  std::vector<std::shared_ptr<Shader>> m_shaders;
};

} // namespace bez

#endif // MESH_H
