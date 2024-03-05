#include "Window.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
// dick move not being able to have "window" as a name for a class???

MyWindow::MyWindow() {Setup( "MyWindow", Vector2u(640, 480)); }

MyWindow::MyWindow(const string& title, const Vector2u& size) // window size?
{
	Setup(title, size);
}
MyWindow::~MyWindow() { Destroy(); }

void MyWindow::Setup(const string& title, const Vector2u& size) // same Q here ?  don't underastand the "Setup"
{
	windowTitle = title;
	windowSize = size;
	isFullscreen = false;
	isDone = false;
	Create();
}

RenderWindow& MyWindow::GetRenderWindow() { return window; }

void MyWindow::Create() // this whole thing is a mess? .. read about it .. still don't get it ...
{
	auto style{0};
	if (isFullscreen)
	{
		style = Style::Fullscreen;
	}
	else
	{
		style = Style::Default;
	}
	window.create({ windowSize.x,windowSize.y, 32 }, windowTitle, style); // what's happening here?
}
void MyWindow::Destroy()
{
	window.close();
}
void MyWindow::Update() 
{
	Event event; // this is so the buttons we press works .. something, something ..
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			isDone = true;
		}
		else if (event.type == Event::KeyPressed&&event.key.code == Keyboard::F5)
		{
			ToggleFullscreen();
		}
	}
}
void MyWindow::ToggleFullscreen() // read more about ... kinda understand .. window gets bigger ish
{
	isFullscreen = !isFullscreen;
	Destroy();
	Create();
}
void MyWindow::BeginDraw() { window.clear(Color::Black); }
void MyWindow::EndDraw() { window.display(); }

bool MyWindow::IsDone() { return isDone; }
bool MyWindow::IsFullscreen() { return isFullscreen; }
Vector2u MyWindow::GetWindowSize() { return windowSize; }

void MyWindow::Draw(Drawable& drawable) 
{
	window.draw(drawable);
}