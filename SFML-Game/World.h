#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Snake.h"
using namespace sf;
class World
{
	Vector2u windowSize; // what does u stand for?
	Vector2i appleItem;
	int blockSize;

	CircleShape appleShape;
	RectangleShape bounds[4]; // not sure what this is?? is it the playerfield that is a rectangle so = 4 corners? or 4 walls?
public:
	World(Vector2u one_windSize); // wind??
	~World();

	int GetBlockSize();
	void RespawnApple();
	void Update(Snake& one_player);
	void Render(RenderWindow& one_window);
};

