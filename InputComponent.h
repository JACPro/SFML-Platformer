#pragma once

#include "Component.h"
#include "SFML/Window.hpp"

class InputComponent : public Component
{
public:
	InputComponent() : mButtonStatus(nullptr) { }
	virtual ~InputComponent() { }

	virtual void Update(float deltaTime) override { }

	void SetButtonStatusRef(const ButtonStatus* newButtonStatus) { mButtonStatus = newButtonStatus; }
	void ClearButtonStatusRef() { mButtonStatus = nullptr; }

	virtual void OnKeyDown(sf::Keyboard::Key key) = 0;
	virtual void OnKeyUp(sf::Keyboard::Key key) = 0;
	virtual void OnKeyHeld(sf::Keyboard::Key key) = 0;

protected:
	const ButtonStatus* mButtonStatus;
};
