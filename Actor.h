#pragma once

#include "Entity.h"
#include "MoveComponent.h"
#include "HealthComponent.h"

class Actor : public Entity
{
public: 
	Actor(World& world, const sf::Texture& texture);
	virtual ~Actor() { }

	virtual void Update(float deltaTime) override;
	virtual void Destroy();

	const MoveComponent& GetMoveComponent() const { return mMoveComponent; }
	const HealthComponent& GetHealthComponent() const { return mHealthComponent; }

protected:
	MoveComponent mMoveComponent;
	HealthComponent mHealthComponent;
};
