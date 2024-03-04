#include "World.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

World::World(Vector2u one_windSize)
{
	blockSize = 16;
	windowSize = one_windSize;
	RespawnApple();
	
	appleShape.setFillColor(Color::Red);
	appleShape.setRadius(blockSize / 2); // why split by 2?
	for (int i = 0; i < 4; i++)
	{
		bounds[i].setFillColor(Color(150, 0, 0)); // why is the color printed out i numbers here?
		if (!(i + 1) % 2) // why modulo??
		{
			bounds[i].setSize(Vector2f(windowSize.x, blockSize));
		}
		else
		{
			bounds[i].setSize(Vector2f(blockSize, windowSize.y)); // why is it printed out the opposite from the if?
		}
		if (i < 2) // what's 2? what sides/corners???
		{
			bounds[i].setPosition(0, 0); // centre?? 
		}
		else
		{
			bounds[i].setOrigin(bounds[i].getSize());
			bounds[i].setPosition(Vector2f(windowSize));
		}
	}
}
World:: ~World() {};
