#pragma once

#include "Component.h"

class MoveComponent : public Component
{
public:
	MoveComponent(bool hasGravity, sf::Vector2f& position);
	virtual ~MoveComponent() { }

	virtual void Update(float deltaTime) override;
	
	const sf::Vector2f GetPosition() const { return mPosition; }
	const sf::Vector2f GetVelocity() const { return mVelocity; }

	void HandleInput(sf::Vector2f input);

private:
	const float GRAVITY = -10.0f;

	//TODO need a reference to CollisionComponent so can ce

	sf::Vector2f& mPosition;
	sf::Vector2f mVelocity = sf::Vector2f(0.0f, 0.0f);
	float mMoveSpeed = 100.0f;
	bool mHasGravity;
};
