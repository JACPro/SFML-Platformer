#include "MoveComponent.h"
#include "MathFunctions.h"

MoveComponent::MoveComponent(bool hasGravity, sf::Vector2f& position)
	: mHasGravity(hasGravity)
	, mPosition(position)
{
}

void MoveComponent::Update(float deltaTime)
{
	mPosition += (mVelocity * deltaTime);
}

void MoveComponent::HandleInput(sf::Vector2f input)
{
	mVelocity = Normalize(input) * mMoveSpeed;
}
