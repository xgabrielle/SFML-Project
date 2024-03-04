#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
enum class Direction{None, Up, Down, Left, Right};
using SnakeContainer = std::vector<SnakeSegment>;
struct SnakeSegment
{
	SnakeSegment(int x, int y) : position(x, y) {};
	sf :: Vector2i position;
};
class Snake
{
	
};

