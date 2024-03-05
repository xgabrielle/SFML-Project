#pragma once
#include "Window.h"
#include "World.h"
#include "Snake.h"
class Game
{
	
	MyWindow window;
	Clock clock;
	Time elapsed;
	World world;
	Snake snake;
	
	// missing code here

public:
	Game();
	~Game();
	Time GetElapsed();
	void RestartClock();
	void HandleInput();
	void Update();
	void Render();
	MyWindow* GetWindow();

	// missing code here ..

};

