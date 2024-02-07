#include "MoveComponent.h"

MoveComponent::MoveComponent(bool hasGravity, sf::Vector2f& position)
	: mHasGravity(hasGravity)
	, mPosition(position)
{
}

void MoveComponent::Update(float deltaTime)
{
	mPosition += (mVelocity * deltaTime);
}
