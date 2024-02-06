#pragma once

#include "Actor.h"
#include "PlayerInputComponent.h"

class Player : public Actor, public PlayerInputComponent
{
public:
	Player(World& world, const sf::Texture& texture);

	void Update(float deltaTime) override;

private:
};
