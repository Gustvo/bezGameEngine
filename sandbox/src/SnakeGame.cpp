#include "SnakeGame.h"

#include <SDL2/SDL.h>

class Sandbox : public bez::Application
{
public:
    Sandbox()
    {

        BEZ_INFO("Initializing app");
        Application::init("Snake Game", 800, 450);

        BEZ_INFO("Creating SnakeGame layer");
        pushLayer(new SnakeGame);
        pushOverlay(new bez::ImGuiLayer);
    }

    ~Sandbox() = default;
};

bez::Application *bez::CreateApplication()
{
    return new Sandbox();
}

void SnakeGame::onAttach()
{
    BEZ_INFO("Creating Shader");
    Shader *myShader = new Shader("default");

	if (myShader == nullptr)
		BEZ_CRIT("Failed to create Shader");

    m_shaders.addResource("default", std::move(myShader));

    m_player = std::make_unique<Player>(m_shaders.getResource("default"));

    m_orthoProj = glm::ortho(0.f, 160.f, 0.f, 90.f, 0.1f, 500.f);
    m_camera = glm::mat4(1.f);
    m_camera = glm::translate(m_camera, glm::vec3(0.f, 0.f, -3.f));

    m_timeLastUpdate = SDL_GetTicks();
}

void SnakeGame::onUpdate()
{
    for (auto &shader : m_shaders.getResourceContainer()) {
        shader.second->setUniform("view", m_camera);
        shader.second->setUniform("projection", m_orthoProj);
    }
    if (SDL_GetTicks() - m_timeLastUpdate >= 500) {
        m_timeLastUpdate = SDL_GetTicks();
        m_player->update();
    }

    m_player->draw();
    if (m_player->checkCollision())
        m_active = false;
    //    m_window->draw(*m_player);
}

void SnakeGame::onDetach()
{
    BEZ_INFO("Freeing resources");
    m_shaders.getResourceContainer().clear();
}


void SnakeGame::onEvent(bez::Event &event)
{
    bez::EventDispatcher eventDispatcher(event);

    eventDispatcher.dispatch<bez::KeyPressedEvent>(std::bind(&SnakeGame::handleInput, this, std::placeholders::_1));

    eventDispatcher.dispatch<bez::KeyReleasedEvent>(std::bind(&SnakeGame::handleInput, this, std::placeholders::_1));
}

bool SnakeGame::handleInput(bez::KeyEvent &p_event)
{
    Keycode keycode = p_event.getKeyCode();

    if (bez::Input::isKeyPressed(BEZ_KEYCODE_DOWN) || bez::Input::isKeyPressed(BEZ_KEYCODE_S))
        m_player->setDirection(DOWN);
    else if (bez::Input::isKeyPressed(BEZ_KEYCODE_UP) || bez::Input::isKeyPressed(BEZ_KEYCODE_W))
        m_player->setDirection(UP);
    else if (bez::Input::isKeyPressed(BEZ_KEYCODE_RIGHT) || bez::Input::isKeyPressed(BEZ_KEYCODE_D))
        m_player->setDirection(RIGHT);
    else if (bez::Input::isKeyPressed(BEZ_KEYCODE_LEFT) || bez::Input::isKeyPressed(BEZ_KEYCODE_A))
        m_player->setDirection(LEFT);

    if (bez::Input::isKeyPressed(BEZ_KEYCODE_Q))
        bez::Application::getApplication().stop();

    if (bez::Input::isKeyPressed(BEZ_KEYCODE_J) && !bez::Input::isKeyRepeated(keycode))
        m_player->crouch();

    if (bez::Input::isKeyRepeated(keycode))
        BEZ_INFO("Key repeated:", keycode);

    return true;
}


