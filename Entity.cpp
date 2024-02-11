#include "Entity.h"

Entity::Entity(World& world, const sf::Texture& texture)
	: mWorld(world)
	, mSprite(texture)
	, mEnabled(true)
{
	mSprite.setOrigin(sf::Vector2f(texture.getSize()) * 0.5f);
}

void Entity::Update(float deltaTime)
{
	mSprite.setPosition(mPosition);
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
