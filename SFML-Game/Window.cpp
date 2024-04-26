#include "Window.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
// not being able to have "window" as a name for a class???

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


void MyWindow::Create() // this whole thing is a mess? .. read about it .. still don't get it ...
{
	auto style{ 0 };
	if (isFullscreen)
	{
		style = Style::Fullscreen; // does what it says .. i think??
	}

	else
	{
		style = Style::Default; // can swap between  Titlebar | Resize | Close

	}
	window.create({ windowSize.x,windowSize.y, 32 }, windowTitle, style); // what's happening here? invokes it??
}

void MyWindow::Destroy()
{
	window.close();
}

void MyWindow::BeginDraw() { window.clear(Color::Black); }
void MyWindow::EndDraw() { window.display(); }

bool MyWindow::IsDone() { return isDone; }
bool MyWindow::IsFullscreen() { return isFullscreen; }

RenderWindow& MyWindow::GetRenderWindow() { return window; }

Vector2u MyWindow::GetWindowSize() { return windowSize; }

void MyWindow::ToggleFullscreen() // read more about ... kinda understand .. window gets bigger ish
{
	isFullscreen = !isFullscreen;
	Destroy();
	Create();
}

void MyWindow::WUpdate()
{
	Event event; // this is so the buttons we press works .. something, something ..
	while (window.pollEvent(event)) // don't know what any of this does. Nothing changes when you comment it out??
	{
		if (event.type == Event::Closed)
		{
			cout << event.type << endl;
			isDone = true;

		}
		else if (event.type == Event::KeyPressed && event.key.code == Keyboard::F5)
		{
			ToggleFullscreen();
		}
	}
}




//void MyWindow::Draw(Drawable& drawable) 
//{
//	window.draw(drawable);
//}