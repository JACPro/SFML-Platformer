#include "PlayerInputComponent.h"

PlayerInputComponent::PlayerInputComponent(MoveComponent& moveComponent)
	: mMoveComponent(moveComponent)
{
}

void PlayerInputComponent::OnKeyDown(sf::Keyboard::Key key)
{
	switch (key)
	{
	case(sf::Keyboard::A):
		printf("A button pressed\r\n");
		break;
	case(sf::Keyboard::D):
		printf("D button pressed\r\n");
		break;
	case(sf::Keyboard::W):
		printf("W button pressed\r\n");
		break;
	case(sf::Keyboard::S):
		printf("S button pressed\r\n");
		break;
	case(sf::Keyboard::Space):
		printf("Space button pressed\r\n");
		break;
	}
}

void PlayerInputComponent::OnKeyUp(sf::Keyboard::Key key)
{
	switch (key)
	{
	case(sf::Keyboard::A):
		printf("A button released\r\n");
		break;
	case(sf::Keyboard::D):
		printf("D button released\r\n");
		break;
	case(sf::Keyboard::W):
		printf("W button released\r\n");
		break;
	case(sf::Keyboard::S):
		printf("S button released\r\n");
		break;
	case(sf::Keyboard::Space):
		printf("Space button released\r\n");
		break;
	}
}

void PlayerInputComponent::OnKeyHeld(sf::Keyboard::Key key)
{
	switch (key)
	{
	case(sf::Keyboard::A):
		printf("A button held\r\n");
		break;
	case(sf::Keyboard::D):
		printf("D button held\r\n");
		break;
	case(sf::Keyboard::W):
		printf("W button held\r\n");
		break;
	case(sf::Keyboard::S):
		printf("S button held\r\n");
		break;
	case(sf::Keyboard::Space):
		printf("Space button held\r\n");
		break;
	}
}
