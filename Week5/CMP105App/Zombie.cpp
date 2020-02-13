#include "Zombie.h"

Zombie::Zombie() {
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 10.f);

	setVelocity(40, 0);

}

void Zombie::update(float dt) {
	setTextureRect(walk.getCurrentFrame());
}

void Zombie::handleInput(float dt) {
	float movement = velocity.x * dt;
	if (input->isKeyDown(sf::Keyboard::Right)) {
		if (walk.getFlipped()) {
			walk.setFlipped(false);
		}
		walk.animate(dt);
		setPosition(getPosition().x + movement, getPosition().y);
	}
	else if (input->isKeyDown(sf::Keyboard::Left)) {
		if (!walk.getFlipped()) {
			walk.setFlipped(true);
		}
		walk.animate(dt);
		setPosition(getPosition().x - movement, getPosition().y);
	}
	else {
			walk.reset();
	}
}
