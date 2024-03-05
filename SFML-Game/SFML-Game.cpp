// SFML-Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Window.h"
#include "Snake.h"
#include "World.h"
using namespace sf;

int main()
{
   
    void main(int argc, char** argv[]);
    {
        
        Event event;
   
        Game game;
        Clock clock;
        Time time = clock.getElapsedTime();
       
        while (!game.GetWindow()->IsDone()) {
           
            game.HandleInput();
            game.Update();
            game.Render();
            game.RestartClock();

            Time elapsed = clock.getElapsedTime();
            float seconds = time.asSeconds();
            Int32 milliseconds = time.asMilliseconds();
            Int64 microseconds = time.asMicroseconds();
            time = clock.restart();


            float fElapsed = elapsed.asSeconds();
            
        }
    }

    return 0;
}

