#pragma once

#include "Entity.h"
#include "HealthComponent.h"
#include "MoveComponent.h"

class Player : public Entity, public HealthComponent, public MoveComponent
{
public:
	Player(World& world, const sf::Texture& texture);

private:
};
