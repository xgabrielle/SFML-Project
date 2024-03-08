#include "World.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

World::World(Vector2u windSize)
{
	blockSize = 16;
	windowSize = windSize;
	RespawnApple();
	
	appleShape.setFillColor(Color::Red);
	appleShape.setRadius(blockSize / 2); // why split by 2?
	for (int i = 0; i < 4; i++)
	{
		bounds[i].setFillColor(Color(150, 0, 0)); // why is the color printed out i numbers here?
		if (!(i + 1) % 2) // why modulo (lol,beer)??
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

void World::Update(Snake& player)
{
	if (player.GetPosition() == appleItem)
	{
		player.Extend();
		player.IncreaseScore();
		RespawnApple();
	}
	int gridSizeX = windowSize.x / blockSize; // maths???
	int gridSizeY = windowSize.y / blockSize;

	if (player.GetPosition().x <= 0 || player.GetPosition().y <= 0 || player.GetPosition().x >= gridSizeX - 1 || player.GetPosition().y >= gridSizeY - 1) // if you smash into the
		                                                                                                                                                                  // wall only or itself too??
	{
		player.Lose();
	}
}
void World::Render(RenderWindow& window) // why do we have a reference here?
{
	for (int i = 0; i < 4; i++)
	{
		window.draw(bounds[i]); // drawing the lines of the world?
	}
	window.draw(appleShape); // apple block?
}

int World::GetBlockSize() { return blockSize; } // i don't understand these returns?? why are we returning 16?? cuz that's the size of the world?? how??
