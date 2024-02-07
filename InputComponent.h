#pragma once

#include "Component.h"
#include "SFML/Window.hpp"

class InputComponent : public Component
{
public:
	InputComponent() { }
	virtual ~InputComponent() { }

	virtual void Update(float deltaTime) override { }

	virtual void HandleButtonPress(sf::Keyboard::Key button) = 0;
};
