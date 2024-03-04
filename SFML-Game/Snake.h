#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
enum class Direction{None, Up, Down, Left, Right};
using SnakeContainer = std::vector<SnakeSegment>;
using namespace sf;
struct SnakeSegment
{
	SnakeSegment(int x, int y) : position(x, y) {};
	Vector2i position;
};
class Snake
{
	void CheckCollision();
	SnakeContainer snakeBody;
	int graphicsSize;
	Direction direction;
	int snakeSpeed;
	int lives;
	int score;
	bool hasLost;
	RectangleShape bodyRectangle;

public:
	Snake(int one_blockSize);
    ~Snake();

	void SetDirection(Direction one_direction);
	Direction GetDirection();
	int GetSpeed();
	Vector2i GetPosition();
	int GetLives();
	int GetScore();
	void IncreaseScore();
	bool HasLost();
	void Lose();
	void ToggleLost();
	void Extend();
	void Reset();
	void Move();
	void Tick();
	void Cut(int one_segments);
	void Render(RenderWindow& one_window);
};

