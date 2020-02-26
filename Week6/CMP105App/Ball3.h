#pragma once
#include "Framework/GameObject.h"
#include <iostream>
#include "Framework/Vector.h"
using namespace std;
class Ball3 :
	public GameObject
{
protected:
	sf::Vector2f mouse_down;
	sf::Vector2f mouse_up;
	sf::Vector2f direction;
	sf::Vector2f gravity;
	sf::Vector2f Velocity;
	float scale;
	sf::Vector2f acceleration;
	sf::Vector2f pos;
	bool drag;

public:
	// Set the window component
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }
	//Window Component
	sf::RenderWindow* window;
	void handleInput(float dt);
	void update(float dt);
	Ball3();

};

