#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "Snake!");
    sf::RectangleShape snake;
    snake.setSize(Vector2f(50,50));
    snake.setFillColor(sf::Color::Blue);
    snake.setPosition(550.00, 450.00);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(snake);
        window.display();

    }

    return 0;
}
