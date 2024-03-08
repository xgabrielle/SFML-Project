#include "Game.h"

#include <iostream>
#include <SFML/Graphics.hpp>

Game::Game() : window("Snake", Vector2u(800, 600)), snake(world.GetBlockSize()), world(Vector2u(800, 600)){}
Game :: ~Game(){}

void Game::HandleInput() 
{
	if(Keyboard::isKeyPressed(Keyboard::Up) && snake.GetDirection() != Direction::Down)
	{
		cout << "up?\n";
		snake.SetDirection(Direction::Up); 
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down) && snake.GetDirection() != Direction::Up)
	{
		cout << "down?\n";
		snake.SetDirection(Direction::Down);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left) && snake.GetDirection() != Direction::Right)
	{
		cout << "left?\n";
		snake.SetDirection(Direction::Left);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) && snake.GetDirection() != Direction::Left)
	{
		cout << "right?\n";
		snake.SetDirection(Direction::Right);
	}
};
Time Game::GetElapsed() { return elapsed; }
void Game::RestartClock() { elapsed = clock.restart(); }

//void Game::RestartClock()
//{
//	
//	float frametime = 1.0f / 60.0f;
//	if (elapsed.asSeconds() >= frametime)
//	{
//		elapsed -= seconds(frametime);
//	}
//}



void Game::Update() 
{
	elapsed += clock.restart();
	float timestep = 1.0f / snake.GetSpeed();
	if (elapsed >= seconds (timestep))
	{
		snake.Tick();
		world.Update(snake);
		elapsed -= seconds (timestep);
		if (snake.HasLost())
		{
			snake.Reset();
		}
	}
};


void Game::Render() 
{
	window.BeginDraw();
	world.Render(window.GetRenderWindow());
	snake.Render(window.GetRenderWindow());
	window.EndDraw();
};

MyWindow* Game::GetWindow() { return &window; }

