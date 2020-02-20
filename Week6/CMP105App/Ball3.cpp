#include "Ball3.h"

Ball3::Ball3()
{
	speed = 50.f;
	acceleration = 50.f;
	newmousepos = sf::Vector2f(0.f, 0.f);
	drag = false;
}

void Ball3::handleInput(float dt)
{
	if (input->isMouseLDown() && drag == false)
	{
		newmousepos.x = input->getMouseX();
		newmousepos.y = input->getMouseY();
		drag = true;
	}
	drag = false;
}

void Ball3::update(float dt)
{
	direction = newmousepos - getPosition();
	direction = Vector::normalise(direction);
	velocity += (direction * speed) * dt; // accelerated
	setPosition(getPosition() + (velocity * dt));
}