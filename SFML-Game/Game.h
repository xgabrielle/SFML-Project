#pragma once
#include "Window.h"
#include "World.h"
#include "Snake.h"
class Game
{
	
	MyWindow window;

	World world;
	Snake snake;
	// missing code here

public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();
	MyWindow* GetWindow();

	// missing code here ..

};

