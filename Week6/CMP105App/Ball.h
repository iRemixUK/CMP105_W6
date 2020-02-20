#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class Ball:
	public GameObject
{
protected:
	float scale;
	bool isJumping;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	sf::Vector2f jumpVector;
public:
	// Set the window component
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }
	//Window Component
	sf::RenderWindow* window;


	Ball();
	~Ball();
	void update(float dt);
	void handleInput(float dt);

};

