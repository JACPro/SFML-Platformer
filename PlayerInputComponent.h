#pragma once

#include "InputComponent.h"
#include "MoveComponent.h"

class PlayerInputComponent : public InputComponent
{
public:
	PlayerInputComponent(MoveComponent& moveComponent);
	virtual ~PlayerInputComponent() { }

	virtual void Update(float deltaTime) override;

	void HandleButtonPress(sf::Keyboard::Key button) override;

private:
	MoveComponent& mMoveComponent;
};
