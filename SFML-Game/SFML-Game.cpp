// SFML-Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Window.h"
using namespace sf;

int main()
{
        Game game;

        
        while (!game.GetWindow()->IsDone()) 
        {
            Event event;
            while (game.GetWindow()->GetRenderWindow().pollEvent(event))
            {
                if (event.type == Event:: Closed)
                { 
                   game.GetWindow()->Create();
                   
                
                }
            }
            if (game.GetWindow()->IsDone())
                break;
            Clock clock;
            game.HandleInput();
            game.Update();
            game.Render();
            game.RestartClock();

            Time elapsed = clock.restart();
            float fElapsed = elapsed.asSeconds(); 
        }
   

    return 0;
}

//#include <SFML/Graphics.hpp>
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Minimal Example");
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//        }
//
//        window.clear(sf::Color::White);
//        window.display();
//    }
//
//    return 0;
//}
