#ifndef PADDLE_H
#define PADDLE_H
#include <SFML/Graphics.hpp>

class paddle
{
    public:
        paddle(float startx, float starty);

        sf::RectangleShape getShape();
        sf::FloatRect getPosition();

        void movingLeft();
        void movingRight();
        void stopLeft();
        void stopRight();

        void update(sf::Time dt);

    private:
    sf::RectangleShape m_shape;
    sf::Vector2f m_position;
    float m_speed = 1100.0f;

    bool m_moveleft = false;
    bool m_moveright = false;

};

#endif // PADDLE_H

