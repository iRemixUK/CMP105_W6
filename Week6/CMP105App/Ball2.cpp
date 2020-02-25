#include "Ball2.h"

Ball2::Ball2()
{
	speed = 50.f; 
	acceleration = 50.f; 
}

void Ball2::handleInput(float dt)
{
	target = sf::Vector2f(input->getMouseX(), input->getMouseY());
}
void Ball2::update(float dt)
{
	// calculate direction and move
	direction = target - getPosition(); 
	direction = Vector::normalise(direction);
	velocity += (direction * speed) *dt; // accelerated
	setPosition(getPosition() + (velocity*dt));

	// if object is close enough to target
	if (Vector::magnitude(target - getPosition()) < 10.f)
	{
		setPosition(target);
	}

	if (Vector::magnitude(target - getPosition()) < 50.f)
	{
		velocity = sf::Vector2f (0.f,0.f);
	}

	
}