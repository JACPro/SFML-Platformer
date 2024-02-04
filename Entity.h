#pragma once

#include "World.h"

class Entity
{
public:
	Entity(World& world, const sf::Texture& texture);
	virtual ~Entity() { }
};
