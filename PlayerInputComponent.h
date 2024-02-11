#pragma once

#include "InputComponent.h"
#include "MoveComponent.h"

class PlayerInputComponent : public InputComponent
{
public:
	PlayerInputComponent(MoveComponent& moveComponent);
	virtual ~PlayerInputComponent() { }

	//virtual void Update(float deltaTime) override;

	virtual void OnKeyDown(sf::Keyboard::Key key) override;
	virtual void OnKeyUp(sf::Keyboard::Key key) override;
	virtual void OnKeyHeld(sf::Keyboard::Key key) override;

private:
	MoveComponent& mMoveComponent;
};
