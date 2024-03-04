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

void World::RespawnApple()
{
	int maxX = (windowSize.x / blockSize) - 2;
	int maxY = (windowSize.y / blockSize) - 2; // don't understand the math on either ..
	appleItem = Vector2i(rand() % maxX + 1, rand() % maxY + 1);
	appleShape.setPosition(appleItem.x * blockSize, appleItem.y * blockSize); // i guess this make sure that the random spot for the apple are inside the world? also the math here ..tf??
}

void World::Update(Snake& one_player)
{
	if (one_player.GetPosition() == appleItem)
	{
		one_player.Extend();
		one_player.IncreaseScore();
		RespawnApple();
	}
	int gridSizeX = windowSize.x / blockSize; // maths???
	int gridSizeY = windowSize.y / blockSize;

	if (one_player.GetPosition().x <= 0 || one_player.GetPosition().y <= 0 || one_player.GetPosition().x >= gridSizeX - 1 || one_player.GetPosition().y >= gridSizeY - 1) // if you smash into the
		                                                                                                                                                                  // wall only or itself too??
	{
		one_player.Lose();
	}
}
