#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "Cell.h"
#include <Drawable.hpp>
#include <memory>
#include <vector>

#define CELL_SIZE 10.f

enum DIRECTION { UP, LEFT, DOWN, RIGHT };

class Player : public bez::Drawable {
public:
  Player(std::shared_ptr<Shader>);
  virtual ~Player();

  void draw() const override;

  void update();
  void setDirection(DIRECTION direction);

  bool checkCollision();

  void crouch();

protected:
private:
  std::vector<Cell> m_cells;
  DIRECTION m_direction;
  DIRECTION m_lastDirection;

  bool m_isCrouching;
};

#endif // PLAYER_H
