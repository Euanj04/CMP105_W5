#include "Mario.h"

Mario::Mario() {
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(1.f / 10.f);

	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(1.f / 10.f);

	duck.addFrame(sf::IntRect(0, 41, 16, 20));
	duck.addFrame(sf::IntRect(16, 41, 16, 20));
	duck.setFrameSpeed(1.f / 10.f);

	setVelocity(50, 50);
}

void Mario::update(float dt) {
	setTextureRect(currentAnimation->getCurrentFrame());
}

void Mario::handleInput(float dt) {
	bool moving = false;
	float movementX = velocity.x * dt;
	float movementY = velocity.y * dt;
	if (input->isKeyDown(sf::Keyboard::Right)) {
		moving = true;
		currentAnimation = &walk;
		if (currentAnimation->getFlipped()) {
			currentAnimation->setFlipped(false);
		}
		setPosition(getPosition().x + movementX, getPosition().y);
	}
	else if (input->isKeyDown(sf::Keyboard::Left)) {
		moving = true;
		currentAnimation = &walk;
		if (!currentAnimation->getFlipped()) {
			currentAnimation->setFlipped(true);
		}
		setPosition(getPosition().x - movementX, getPosition().y);
	}
	if (input->isKeyDown(sf::Keyboard::Down)) {
		moving = true;
		currentAnimation = &duck;
		setPosition(getPosition().x, getPosition().y + movementY);

	}
	if (input->isKeyDown(sf::Keyboard::Up)) {
		moving = true;
		currentAnimation = &swim;
		setPosition(getPosition().x, getPosition().y - movementY);

	}
	if (moving == false) {
		currentAnimation = &walk;
		setSize(sf::Vector2f(15, 21));
		currentAnimation->reset();
	}
	else {
		currentAnimation->animate(dt);
	}
}