#include "Player.h"
#include "ResourceManager.h"

Player::Player(World& world)
	: Actor(world, world.GetResources().GetTextures().mPlayerTex)
	, mPlayerInput(mMoveComponent)
{
	world.AddInputListener(&mPlayerInput);
}

void Player::Update(float deltaTime)
{
	Actor::Update(deltaTime);
}
