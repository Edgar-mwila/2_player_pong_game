#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>

class ball
{
    public:
        ball(float StartX, float StartY);

        sf::FloatRect getPosition();
        sf::RectangleShape getShape();

        float getVelocity();

        void bounceSides();

        void score();

        void hitball();

        void update(sf::Time dt);



    private:
    sf::Vector2f m_position;
    sf::RectangleShape m_BallShape;

    float m_speed = 70;
    float m_directionX = 1.0f;
    float m_directionY = 1.0f;

};

#endif // BALL_H

