#include "Cell.h"

Cell::Cell(glm::vec2 p_pos)
{
    loadData(m_vertices, m_indices);
    setPosition(p_pos.x, p_pos.y, 1.0f);

}

Cell::Cell(float p_x, float p_y)
{
    loadData(m_vertices, m_indices);
    setPosition(p_x, p_y, 1.0f);
}

Cell::~Cell()
{
    //dtor
}

void Cell::move(int x, int y)
{
    Transformable::move(x, y, 0);
}
