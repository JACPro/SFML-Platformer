#include "Player.h"
#include "ResourceManager.h"

Player::Player(World& world)
	: Actor(world, world.GetResources().GetTextures().mPlayerTex)
	, PlayerInputComponent(*this)
{
	world.AddInputListener(this);
}

void Player::Update(float deltaTime)
{
	Actor::Update(deltaTime);
}
