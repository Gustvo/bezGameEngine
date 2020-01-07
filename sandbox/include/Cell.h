#ifndef CELL_H
#define CELL_H

#include <bez/Mesh.hpp>
#include <glm/glm.hpp>

class Cell : public bez::Mesh {
public:
  Cell(glm::vec2 pos);
  Cell(float x, float y);
  virtual ~Cell();

  void move(int x, int y);

protected:
private:
  std::vector<float> m_vertices = {
      0.0f, 0.0f, 0.0f,  1.0f, 0.0f,  0.0f,  0.0f, 10.0f,
      0.0f, 1.0f, 0.0f,  0.0f, 10.0f, 10.0f, 0.0f, 1.0f,
      0.0f, 0.0f, 10.0f, 0.0f, 0.0f,  1.0f,  0.0f, 0.0f,
  };

  std::vector<unsigned int> m_indices = {0, 1, 2, 0, 2, 3};
};

#endif // CELL_H
