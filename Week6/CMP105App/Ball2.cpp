#include "Ball2.h"

Ball2::Ball2()
{
	speed = 50.f; 
	acceleration = 50.f; 
	target = sf::Vector2f(600, 300);
}

void Ball2::update(float dt)
{
	// calculate direction and move
	direction = target - getPosition(); 
	direction = Vector::normalise(direction);
	velocity = (direction * speed); // fixed speed
	setPosition(getPosition() + (velocity*dt));

	// if object is close enough to target
	if (Vector::magnitude(target - getPosition()) < 10.f)
	{
		setPosition(target);
	}
}