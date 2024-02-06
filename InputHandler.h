#pragma once

#include <list>
#include <SFML/Window.hpp>

class InputComponent;

class InputHandler
{
public:
	InputHandler();

	bool AddListener(InputComponent* listener);
	void RemoveListener(InputComponent* listener);
	void PressButton(sf::Keyboard::Key button);

private:
	std::list<InputComponent*> mListeners;
};