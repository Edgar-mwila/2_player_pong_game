#include<iostream>
#include "paddle.h"

paddle::paddle(float startx, float starty)
{
    m_position.x = startx;
    m_position.y = starty;

    m_shape.setSize(sf::Vector2f(50, 5));
    m_shape.setFillColor(sf::Color::Red);
    m_shape.setOutlineThickness(2);

    m_shape.setPosition(m_position);

}

sf::FloatRect paddle::getPosition()
{
    return m_shape.getGlobalBounds();
}

sf::RectangleShape paddle::getShape()
{
    return m_shape;
}

void paddle::movingLeft()
{
    m_moveleft = true;
}

void paddle::stopLeft()
{
    m_moveleft = false;
}

void paddle::movingRight()
{
    m_moveright = true;
}

void paddle::stopRight()
{
    m_moveright = false;
}

void paddle::update(sf::Time dt)
{
    if(m_moveleft)
    {
       m_position.x -= m_speed * dt.asSeconds();
    }

    if(m_moveright)
    {
       m_position.x += m_speed * dt.asSeconds();
    }

    m_shape.setPosition(m_position);
}



