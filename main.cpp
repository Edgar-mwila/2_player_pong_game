#include <SFML/Graphics.hpp>
#include <iostream>
#include <ball.h>
#include <paddle.h>

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");
    sf::RectangleShape field(sf::Vector2f(200.f, 500.f));
    field.setPosition(sf::Vector2f(300.f, 50.f));
    ball myball(400.f, 300.f);
    paddle topPaddle(375.f, 60.f);
    paddle bottomPaddle(305.f, 540.f);
    sf::Clock clock;
    sf::Time dt;

    float bounceTimer = 0.10f;
    while (app.isOpen())
    {

        dt = clock.restart();
        bounceTimer -= dt.asSeconds();

        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        if(myball.getPosition().top + myball.getPosition().height > 550)
        {
            myball.score();
        }

        if(myball.getPosition().top + myball.getPosition().height < 50)
        {
            myball.score();
        }


        if(myball.getPosition().intersects(topPaddle.getPosition()) || myball.getPosition().intersects(bottomPaddle.getPosition()))
        {
        if(bounceTimer < 0)
        {
        myball.hitball();
        bounceTimer = 0.10f;
        }
        }

        if((myball.getPosition().left < 300 || myball.getPosition().left +myball.getPosition().width > 500) && bounceTimer < 0)
        {
            myball.bounceSides();
            bounceTimer = 0.10f;
        }


          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && bottomPaddle.getPosition().left > 300)
        {
            bottomPaddle.movingLeft();
        }
        else
        {
            bottomPaddle.stopLeft();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (bottomPaddle.getPosition().left + bottomPaddle.getPosition().width)  < 500)
        {
            bottomPaddle.movingRight();
        }
        else
        {
            bottomPaddle.stopRight();
        }



        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && topPaddle.getPosition().left > 300)
        {
            topPaddle.movingLeft();
        }
        else
        {
            topPaddle.stopLeft();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && topPaddle.getPosition().left + topPaddle.getPosition().width < 500)
        {
            topPaddle.movingRight();
        }
        else
        {
            topPaddle.stopRight();
        }




        // Clear screen
        app.clear();

        //update our entities
        myball.update(dt);
        topPaddle.update(dt);
        bottomPaddle.update(dt);

        //draw objects
        app.draw(field);
        app.draw(myball.getShape());
        app.draw(topPaddle.getShape());
        app.draw(bottomPaddle.getShape());
        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
