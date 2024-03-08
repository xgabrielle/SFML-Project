#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


struct SnakeSegment
{
	SnakeSegment(int x, int y) : position(x, y) {};
	Vector2i position;
};

enum class Direction { None, Upward, Downward, Leftward, Rightward };
using SnakeContainer = std::vector<SnakeSegment>;

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
	Snake(int blockSize);
    ~Snake();

	void SetDirection(Direction direction);
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
	void Cut(int segments);
	void Render(RenderWindow& window);
};

