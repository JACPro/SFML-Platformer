#pragma once

#include "Entity.h"
#include "MoveComponent.h"
#include "HealthComponent.h"

class Actor : public Entity, public MoveComponent, public HealthComponent
{
public: 
	Actor(World& world, const sf::Texture& texture);
	virtual ~Actor() { }

	virtual void Update(float deltaTime) override;
	virtual void Destroy();

private:
};
