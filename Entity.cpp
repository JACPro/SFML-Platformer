#include "Entity.h"

Entity::Entity(World& world, const sf::Texture& texture)
	: mWorld(world)
	, mSprite(texture)
{
}

void Entity::Update(float deltaTime)
{

}
