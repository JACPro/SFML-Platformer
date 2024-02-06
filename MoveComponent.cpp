#include "MoveComponent.h"

MoveComponent::MoveComponent(bool hasGravity, sf::Vector2f& position)
	: mHasGravity(hasGravity)
	, mPosition(position)
{
}
