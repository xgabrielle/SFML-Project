#include "Snake.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

Snake::Snake(int blockSize)
{
	graphicsSize = blockSize;
	bodyRectangle.setSize(Vector2f(graphicsSize - 1, graphicsSize - 1));
	Reset();
}
Snake::~Snake() {}

void Snake::Reset()
{
	snakeBody.clear();
	snakeBody.push_back(SnakeSegment(5, 7)); // look up push_back again ..
	snakeBody.push_back(SnakeSegment(5, 6));
	snakeBody.push_back(SnakeSegment(5, 5));

	SetDirection(Direction::None);
	snakeSpeed = 15;
	lives = 3;
	score = 0;
	hasLost = false;
}
void Snake::SetDirection(Direction direction) { this->direction = direction; }
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

void Snake::Extend()
{
	if (snakeBody.empty()) { return; } // what does empty stand for??
	
	SnakeSegment& tail_head = snakeBody[snakeBody.size() - 1]; // reference and [snakeBody.size()-1] = something with the memory. Give space without holding space .. something, something ..
	                                   // adding more body but why is it negative?
	
	if (snakeBody.size() > 1) {} // not sure what this one does since there's nothing inbetween {}?? need a better explanation for the 'size'
	
	SnakeSegment& tail_bone = snakeBody[snakeBody.size() - 2]; // same as line 53,54. Again, why negative?
		
	

	if (tail_head.position.x == tail_bone.position.x)
	{
		if (tail_head.position.y > tail_bone.position.y)
		{
			snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
		}
		else
		{
			snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
		}
	}
	else if (tail_head.position.y == tail_bone.position.y)
	{
		if (tail_head.position.x > tail_bone.position.x)
		{
			snakeBody.push_back(SnakeSegment(tail_head.position.x + 1, tail_head.position.y));
		}
		else
		{
			snakeBody.push_back(SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
		}
	}
	else
	{
		if (direction == Direction::Upward)
		{
			snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
		}
		else if (direction == Direction::Downward)
		{
			snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
		}
		else if (direction == Direction::Leftward)
		{
			snakeBody.push_back(SnakeSegment(tail_head.position.x + 1, tail_head.position.y)); // shouldn't x be -1?
		}
		else if (direction == Direction::Rightward)
		{
			snakeBody.push_back(SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
		}
	}

}
void Snake::Tick() // this name needs more explanation ..
{
	if (snakeBody.empty()) { return; }
	if (direction == Direction::None) { return; } // none = standing still?
	Move();
	CheckCollision();
}
void Snake::Move()
{
	for (int i = snakeBody.size()-1; i > 0; i--) // not sure about this for-loop either??
	{
		snakeBody[i].position = snakeBody[i - 1].position;
	}
	if (direction == Direction::Leftward)
	{
		--snakeBody[0].position.x; // can i have the '--' after instead of front? is that the same??
	}
	else if (direction == Direction::Rightward)
	{
		++snakeBody[0].position.x;
	}
	else if (direction == Direction::Upward)
	{
		--snakeBody[0].position.y; // why is this negative
	}
	else if (direction == Direction::Downward)
	{
		++snakeBody[0].position.y; // and this positive?
	}
}
void Snake::CheckCollision()
{
	if (snakeBody.size() < 5) { return; } // not sure what the "over 4 segments" mean??
	SnakeSegment& head = snakeBody.front();
	for (auto itr = snakeBody.begin()+1; itr != snakeBody.end(); itr++)// what does itr stand for?
	{
		if (itr->position == head.position) // i guess this is if the head smashes into the snake body??
		{
			int segments = snakeBody.end() - itr;
			Cut(segments); // does this mean we're only losing a bir of our tail/point?
			break;
		}
	}
}
void Snake::Cut(int one_segments) // why can't i use numbers in the name when the book does it??
{
	for (int i = 0; i < one_segments; i++)
	{
		snakeBody.pop_back(); // look up pop_back??
	}
	--lives;
	if (!lives) { Lose();return; } // do we lose body or just life?
}
void Snake::Render(RenderWindow& one_window)
{
	if (snakeBody.empty()) { return; }
	auto head = snakeBody.begin();
	bodyRectangle.setFillColor(Color::White); // snakes head
	bodyRectangle.setPosition(head->position.x * graphicsSize, head->position.y * graphicsSize);
	one_window.draw(bodyRectangle);

	bodyRectangle.setFillColor(Color::Magenta); // snakes body
	for (auto itr = snakeBody.begin()+1; itr != snakeBody.end(); itr++)
	{
		bodyRectangle.setPosition(itr->position.x * graphicsSize, itr->position.y * graphicsSize);
		one_window.draw(bodyRectangle);
	}
}
