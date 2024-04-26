// SFML-Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace sf;

int main()
{
        Game game;
        while (!game.GetWindow()->IsDone()) 
        {
            game.HandleInput();
            game.Update();
            game.Render();
            //game.RestartClock();
        }
   

    return 0;
}

