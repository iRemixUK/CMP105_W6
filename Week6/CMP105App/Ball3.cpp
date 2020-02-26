#include "Ball3.h"

Ball3::Ball3()
{
	scale = 200.f;
	//gravity = sf::Vector2f(0, 9.8f) * scale;
	//acceleration = sf::Vector2f(-2.f, 2.f) * scale;
	drag = false;
	
}

void Ball3::handleInput(float dt)
{
	if (input->isMouseLDown() && drag == false)
	{
		setPosition(input->getMouseX(), input->getMouseY()); // Set position of ball to left click 
		mouse_down = sf::Vector2f(input->getMouseX(), input->getMouseY()); // Get position of that ball
		Velocity = sf::Vector2f(0.f,0.f) * scale; // Set Velocity and Gravity to 0 so ball doesn't move straight away
		gravity = sf::Vector2f(0, 0)  *scale;
		drag = true;
	}

	if (!input->isMouseLDown() && drag == true)
	{
		mouse_up = sf::Vector2f(input->getMouseX(), input->getMouseY());
		drag = false;
		
		Velocity = sf::Vector2f(5, -5.f) * scale;
		gravity = sf::Vector2f(0, 9.8f) *scale;
	}
	

}

void Ball3::update(float dt)
{
	sf::Vector2u WinSize = window->getSize();
	sf::Vector2f ObjectSize = getSize();

	direction = mouse_up - mouse_down;
	direction = Vector::normalise(direction);
	// Horizontal Calculation
	// s = v * t
	pos.x = (direction.x * Velocity.x) * dt;

	// Vertical Calculation
	//ut + 1 / 2at ^2
	pos.y = (Velocity.y * dt) + (0.5f * gravity.y * dt * dt);

	Velocity += gravity * dt;
	Velocity -= acceleration * dt;  
	setPosition(getPosition() + (pos));

	// Check for collision with bottom of window
	if (getPosition().y > WinSize.y - ObjectSize.y)
	{
		setPosition(getPosition().x, WinSize.y - ObjectSize.y);
		Velocity.y = (-Velocity.y) / 1.2f;
	}

	if (getPosition().y < 0)
	{
		setPosition(getPosition().x, 0);
		Velocity.y = (-Velocity.y) / 1.2f;
	}
	if (getPosition().x < 0)
	{
		setPosition(0, getPosition().y);
		Velocity.x = (-Velocity.x) / 1.2f;
	}

	if (getPosition().x > WinSize.x - ObjectSize.x)
	{
		setPosition(WinSize.x - ObjectSize.x, getPosition().y);
		Velocity.x = (-Velocity.x) / 1.2f;
	}

}