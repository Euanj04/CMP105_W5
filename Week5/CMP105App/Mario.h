#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Mario :
	public GameObject
{
public:
	Mario();
	void update(float dt);
	void handleInput(float dt);
	
protected:
	Animation walk;
	Animation swim;
	Animation duck;
	Animation* currentAnimation;
};

