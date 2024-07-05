#include <iostream>
#include <SFML/Graphics.hpp>
#include "Snake.h"
using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "Snake!");
    Clock clock;
    Time timeElapsedSinceLastUpdate = Time::Zero; //variable for keeping up track of how much elapsed since created
    Time TimePerFrame = seconds(0.05f); //one second for each update
    Snake snake(550, 450, Direction::NORTH, 1);

    while (window.isOpen())
    {
        Time elapsedTime = clock.restart(); //restart clock
        timeElapsedSinceLastUpdate += elapsedTime; //adding into elapsed time

        while(timeElapsedSinceLastUpdate > TimePerFrame){ //when time elapsed is bigger than frame time, move can be called
            timeElapsedSinceLastUpdate -= TimePerFrame;
            snake.move();
            cout << snake.positionToString(snake.getPosition()) << endl;
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(Keyboard::isKeyPressed(Keyboard::Up)){
            snake.setDirection(Direction::NORTH);
        } else if(Keyboard::isKeyPressed(Keyboard::Down)){
            snake.setDirection(Direction::SOUTH);
        }

//        sf::Event control;
//        while(window.pollEvent(control)){
//            switch (control.type) {
//                case Event::KeyReleased:
//                    switch (control.key.code) {
//                        case sf::Keyboard::Up:
//                            snake.setDirection(Direction::NORTH);
//                            break;
//                        case sf::Keyboard::Down:
//                            snake.setDirection(Direction::SOUTH);
//                            break;
//                    }
//                    break;
//            }
//        }


        window.clear();
        snake.drawSnake(snake, window);
        window.display();
    }
    return 0;
}
