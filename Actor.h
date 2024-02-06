#pragma once

#include "Entity.h"
#include "MoveComponent.h"
#include "HealthComponent.h"

class Actor : public Entity, public MoveComponent, public HealthComponent
{
public: 
	Actor(World& world, const sf::Texture& texture);
	virtual ~Actor() { }
};
