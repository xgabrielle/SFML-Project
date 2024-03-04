#include "Snake.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

Snake::Snake(int one_blockSize)
{
	graphicsSize = one_blockSize;
	bodyRectangle.setSize(Vector2f(graphicsSize - 1, graphicsSize - 1));
	Reset();
}
Snake::~Snake() {}

void Snake::Reset()
{
	snakeBody.clear();
	snakeBody.push_back(SnakeSegment(5, 7));
	snakeBody.push_back(SnakeSegment(5, 6));
	snakeBody.push_back(SnakeSegment(5, 5));

	SetDirection(Direction::None);
	snakeSpeed = 15;
	lives = 3;
	score = 0;
	hasLost = false;
}
void Snake::SetDirection(Direction one_direction) { direction = one_direction; }
Direction Snake::GetDirection(){ return direction; }
int Snake::GetSpeed() { return snakeSpeed; }

Vector2i Snake :: GetPosition()
{
	if (!snakeBody.empty())
	{
		return snakeBody.front().position;
	}
	else
		return Vector2i(1, 1);
}

int Snake::GetLives() { return lives; }
int  Snake::GetScore(){ return score; }

void Snake::IncreaseScore() { score += 10; }
bool Snake::HasLost() { return hasLost; }
void Snake::Lose() { hasLost = true; }
void Snake::ToggleLost() { hasLost = !hasLost; }
