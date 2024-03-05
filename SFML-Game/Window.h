#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class MyWindow
{

	void Setup(const string& title, const Vector2u& size); // need more understanding here ..
	void Destroy();
	void Create();

	RenderWindow window;
	Vector2u windowSize;
	string windowTitle;
	bool isDone;
	bool isFullscreen;

public:
	MyWindow();
	MyWindow(const string& title, const Vector2u& size);
	~MyWindow();
	RenderWindow& GetRenderWindow();
	void BeginDraw();
	void EndDraw();

	void Update();

	bool IsDone();
	bool IsFullscreen();
	Vector2u GetWindowSize();

	void ToggleFullscreen();

	void Draw(Drawable& drawable);
	
};



