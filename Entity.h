#pragma once

#include "World.h"

class Entity
{
public:
	Entity(World& world, const sf::Texture& texture);
	virtual ~Entity() { }

	virtual void Update(float deltaTime);
	virtual void Render(sf::RenderTexture& rt);

	bool IsEnabled() { return mEnabled; }
	void Enable();
	void Disable();

	sf::Vector2f& GetPosition() { return mPosition; }

private:
	World& mWorld;
	sf::Sprite mSprite;

	sf::Vector2f mPosition = sf::Vector2f(0.0f, 0.0f);

	bool mEnabled;
};
