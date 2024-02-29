// SFML-Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
    sf::RectangleShape rectangle (Vector2f(128.0f, 128.0f));
    rectangle.setFillColor(sf::Color::Magenta);
    rectangle.setPosition(320, 240);
    rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2); // centre the rectangle

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
