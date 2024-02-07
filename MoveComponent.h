#pragma once

#include "Component.h"

class MoveComponent : public Component
{
public:
	MoveComponent(bool hasGravity, sf::Vector2f& position);
	virtual ~MoveComponent() { }

	virtual void Update(float deltaTime) override;

private:
	sf::Vector2f& mPosition;
	sf::Vector2f mVelocity = sf::Vector2f(0.0f, 0.0f);
	bool mHasGravity;
};
