#pragma once

#include "Component.h"
#include "SFML/Window.hpp"

class InputComponent : public Component
{
public:
	virtual ~InputComponent() { }

	virtual void HandleButtonPress(sf::Keyboard::Key button) = 0;
};
