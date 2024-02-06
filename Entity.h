#pragma once

#include "World.h"

class Entity
{
public:
	Entity(World& world, const sf::Texture& texture);
	virtual ~Entity() { }

	void Update(float deltaTime);

private:
	World& mWorld;
	sf::Sprite mSprite;
};
