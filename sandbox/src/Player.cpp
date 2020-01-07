#include "Player.h"

#include <bez/Logger/Log.hpp>

Player::Player(std::shared_ptr<Shader> shader)
{
    m_direction = RIGHT;
    m_lastDirection = m_direction;

    for (int i = 5; i >= 0; --i) {
        Cell cell(10.f * i, 0.f);
        m_cells.push_back(cell);
        m_cells.back().addShader(shader);
    }

    m_isCrouching = false;

}

Player::~Player()
{
    //~dctor
}

void Player::draw() const
{
    for (Cell cell : m_cells) {
        cell.draw();
    }
}

void Player::update()
{
    for (std::vector<Cell>::reverse_iterator iter = m_cells.rbegin(); iter != m_cells.rend()-1; ++iter) {
        iter->setPosition((iter+1)->getPosition());
    }

    if (m_direction == UP)
        m_cells[0].move(0, CELL_SIZE);
    else if (m_direction == DOWN)
        m_cells[0].move(0,-CELL_SIZE);
    else if (m_direction == LEFT)
        m_cells[0].move(-CELL_SIZE, 0);
    else if (m_direction == RIGHT)
        m_cells[0].move(CELL_SIZE, 0);

    if (m_cells[0].getPosition().x < 0)
        m_cells[0].move(16*CELL_SIZE, 0);

    if (m_cells[0].getPosition().x >= 16*CELL_SIZE)
        m_cells[0].move(-16*CELL_SIZE, 0);

    if (m_cells[0].getPosition().y < 0)
        m_cells[0].move(0, 9*CELL_SIZE);

    if (m_cells[0].getPosition().y >= 9*CELL_SIZE)
        m_cells[0].move(0, -9*CELL_SIZE);


    m_lastDirection = m_direction;

}

void Player::setDirection(DIRECTION p_dir)
{
    if (p_dir % 2 == m_lastDirection % 2)
        return;
    m_direction = p_dir;
}

bool Player::checkCollision() {
    for (auto& cell : m_cells) {
        if (&cell == &m_cells[0])
            continue;
        if (m_cells[0].getPosition().x == cell.getPosition().x && m_cells[0].getPosition().y == cell.getPosition().y)
            return true;
    }
    return false;
}

void Player::crouch()
{
    m_isCrouching = !m_isCrouching;
    BEZ_INFO("Player crounch status: ", m_isCrouching ? "active" : "false");
}
