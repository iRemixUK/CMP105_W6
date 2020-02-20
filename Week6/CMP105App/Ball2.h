#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class Ball2 :
	public GameObject
{
protected:
	float speed;
	float acceleration;
	sf::Vector2f target;
	sf::Vector2f direction;

public:
	Ball2();
	// Set the window component
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }
	//Window Component
	sf::RenderWindow* window;

	void update(float dt);
};

