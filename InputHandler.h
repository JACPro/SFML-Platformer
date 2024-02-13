#pragma once

#include <list>
#include <SFML/Window.hpp>

class InputComponent;

struct ButtonStatus
{
	bool mWKeyDown = false;
	bool mAKeyDown = false;
	bool mSKeyDown = false;
	bool mDKeyDown = false;
	bool mSpaceKeyDown = false;
};

class InputHandler
{
public:
	InputHandler() { }

	bool AddListener(InputComponent* listener);
	void RemoveListener(InputComponent* listener);
	
	void CheckButton(sf::Keyboard::Key key, bool& keyDownBool);

	void Update(float deltaTime);
	void OnKeyDown(sf::Keyboard::Key key);
	void OnKeyUp(sf::Keyboard::Key key);
	void OnKeyHeld(sf::Keyboard::Key key);

private:
	std::list<InputComponent*> mListeners;

	ButtonStatus mButtonStatus;
};