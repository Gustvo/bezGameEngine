#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include "Player.h"
#include "ResourceAllocator.hpp"
#include <bez/Shader.hpp>
#include <bezGameEngine.hpp>

class SnakeGame : public bez::Layer {
public:
  SnakeGame() : Layer("Snake Layer"){};
  virtual ~SnakeGame(){};

  // void onCreate();
  void onAttach() override;
  void onDetach() override;
  void onUpdate() override;
  void onEvent(bez::Event &event) override;

  bool handleInput(Keycode key);

protected:
private:
  Player *m_player;
  ResourceAllocator<Shader> m_shaders;
  glm::mat4 m_orthoProj;
  glm::mat4 m_camera;

  unsigned int m_timeLastUpdate;
};

#endif // SNAKEGAME_H
