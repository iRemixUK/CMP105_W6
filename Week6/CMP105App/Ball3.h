#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class Ball3 :
	public GameObject
{
protected:
	sf::Vector2f newmousepos;
	sf::Vector2f startingPos;
	sf::Vector2f direction;
	float speed;
	float acceleration;
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

