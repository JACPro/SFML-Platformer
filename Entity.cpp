#include "Entity.h"

Entity::Entity(World& world, const sf::Texture& texture)
	: mWorld(world)
	, mSprite(texture)
	, mEnabled(true)
{
}

void Entity::Update(float deltaTime)
{

}

void Entity::Render(sf::RenderTexture& rt)
{
	rt.draw(mSprite);
}

void Entity::Enable()
{
	mEnabled = true;
}

void Entity::Disable()
{
	mEnabled = false;
}
