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

   
        Game game;
        while (!game.GetWindow()->IsDone()) {
           
            game.HandleInput();
            game.Update();
            game.Render();
        }
    }

    return 0;
}

