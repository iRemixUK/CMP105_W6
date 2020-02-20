#include "Ball.h"

Ball::Ball()
{
	// initialise gravity value (gravity 9.8, 200 scale, 200 p/s this will need to be uniform)
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	stepVelocity = sf::Vector2f(0.f, 0.f);
	jumpVector = sf::Vector2f(0, -4.0f) * scale;
	isJumping = false;
}

void Ball::update(float dt)
{
	sf::Vector2u WinSize = window->getSize();
	sf::Vector2f ObjectSize = getSize();

	// Apply gravity force, increasing velocity
	// Move shape by new velocity
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt; // ut+ 1/2at^2
	stepVelocity += gravity *dt; // v = u + at  note the += is not =
	setPosition(getPosition() +pos);


	// Check for collision with bottom of window
	if (getPosition().y > WinSize.y - ObjectSize.y)
	{
		isJumping = false;
		setPosition(getPosition().x, WinSize.y - ObjectSize.y);
		stepVelocity = sf::Vector2f(0, 0);
	}
}

void Ball::handleInput(float dt)
{
	// Jump, check if already jumping
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		if (!isJumping)
		{
			stepVelocity = jumpVector;
			isJumping = true;
		}
	}

	// Mouse click to set position of ball 
	if (input->isMouseLDown())
	{
		setPosition(input->getMouseX(), input->getMouseY());
	}
}

Ball::~Ball()
{

}