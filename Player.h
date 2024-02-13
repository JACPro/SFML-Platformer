#pragma once

#include "Actor.h"
#include "PlayerInputComponent.h"

class Player : public Actor
{
public:
	Player(World& world);

	void Update(float deltaTime) override;

protected:
	PlayerInputComponent mPlayerInput;
};
