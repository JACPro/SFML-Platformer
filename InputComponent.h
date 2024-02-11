#pragma once

#include "Component.h"
#include "SFML/Window.hpp"

class InputComponent : public Component
{
public:
	InputComponent() { }
	virtual ~InputComponent() { }

	virtual void Update(float deltaTime) override { }

	virtual void OnKeyDown(sf::Keyboard::Key key) = 0;
	virtual void OnKeyUp(sf::Keyboard::Key key) = 0;
	virtual void OnKeyHeld(sf::Keyboard::Key key) = 0;
};
