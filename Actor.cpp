#include "Actor.h"

Actor::Actor(World& world, const sf::Texture& texture)
	: Entity(world, texture)
	, mHealthComponent(100.0f)
	, mMoveComponent(true, GetPosition())
{
}

void Actor::Update(float deltaTime)
{
	mMoveComponent.Update(deltaTime);
	Entity::Update(deltaTime);

}

void Actor::Destroy()
{
}
