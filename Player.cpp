#include "Player.h"

Player::Player(World& world, const sf::Texture& texture)
	: Actor(world, texture)
	, PlayerInputComponent(*this)
{
	world.AddInputListener(this);
}
