#include "Actor.h"

Actor::Actor(World& world, const sf::Texture& texture)
	: Entity(world, texture)
	, HealthComponent(100.0f)
	, MoveComponent(true)
{
}
