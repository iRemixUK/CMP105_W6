#include "Ball3.h"

Ball3::Ball3()
{
	scale = 200.f;
	acceleration = 5.f;
	drag = false;
}

void Ball3::handleInput(float dt)
{
	if (input->isMouseLDown() && drag == false)
	{
		setPosition(input->getMouseX(), input->getMouseY());
		mouse_down = sf::Vector2f(input->getMouseX(), input->getMouseY());
		Velocity = sf::Vector2f(0.f,0.f);
		gravity = sf::Vector2f(0.f, 0.f);
		drag = true;
	}

	if (!input->isMouseLDown() && drag == true)
	{
		mouse_up = sf::Vector2f(input->getMouseX(), input->getMouseY());
		drag = false;
		gravity = sf::Vector2f(0, 9.8f) *scale;
		Velocity = sf::Vector2f(4.f, 3.f) *scale;
	}

}

void Ball3::update(float dt)
{
	sf::Vector2u WinSize = window->getSize();
	sf::Vector2f ObjectSize = getSize();
	
	direction = mouse_up - mouse_down;
	direction = Vector::normalise(direction);
	std::cout << direction.y << endl;
	std::cout << direction.x << endl;
	
	// Apply gravity force, increasing velocity
	// Move shape by new velocity
	sf::Vector2f pos = (Velocity * dt) + (0.5f * gravity * dt * dt); // ut+ 1/2at^
	Velocity +=  gravity * dt; // v = u + at  note the += is not =
	Velocity -= (direction * acceleration) * dt; // accelerated
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