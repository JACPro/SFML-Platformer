#include "PlayerInputComponent.h"

PlayerInputComponent::PlayerInputComponent(MoveComponent& moveComponent)
	: mMoveComponent(moveComponent)
{
}

void PlayerInputComponent::Update(float deltaTime)
{

}

void PlayerInputComponent::HandleButtonPress(sf::Keyboard::Key button)
{
	switch (button)
	{
		case(sf::Keyboard::A):
			break;
		case(sf::Keyboard::D):
			break;
		case(sf::Keyboard::W):
			break;
		case(sf::Keyboard::S):
			break;
	}
}
