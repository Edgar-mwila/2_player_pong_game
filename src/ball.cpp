#include<iostream>
#include "ball.h"

ball::ball(float StartX, float StartY)
{
    m_position.x = StartX;
    m_position.y = StartY;

    m_BallShape.setSize(sf::Vector2f(10,10));
    m_BallShape.setFillColor(sf::Color::Black);
    m_BallShape.setPosition(m_position);
}

sf::FloatRect ball::getPosition()
{
    return m_BallShape.getGlobalBounds();
}

sf::RectangleShape ball::getShape()
{
    return m_BallShape;
}

float ball::getVelocity()
{
    return m_directionX;
}

void ball::bounceSides()
{
    m_directionX = -m_directionX;
}


void ball::score()
{
    m_position.x = 400;
    m_position.y = 300;
    m_speed = 70;
}

void ball::hitball()
{
    m_directionY = -m_directionY;
}

void ball::update(sf::Time dt)
{
    m_position.x += m_directionX*m_speed*dt.asSeconds();
    m_position.y += m_directionY*m_speed*dt.asSeconds();

    m_BallShape.setPosition(m_position);

    m_speed = m_speed + 0.01;;

}

