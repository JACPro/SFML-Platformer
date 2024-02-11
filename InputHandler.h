#pragma once

#include <list>
#include <SFML/Window.hpp>

class InputComponent;

class InputHandler
{
public:
	InputHandler() { }

	bool AddListener(InputComponent* listener);
	void RemoveListener(InputComponent* listener);
	
	void CheckButton(sf::Keyboard::Key key, bool& keyDownBool);

	void Update();
	void OnKeyDown(sf::Keyboard::Key key);
	void OnKeyUp(sf::Keyboard::Key key);
	void OnKeyHeld(sf::Keyboard::Key key);

private:
	std::list<InputComponent*> mListeners;

	bool mWKeyDown = false;
	bool mAKeyDown = false;
	bool mSKeyDown = false;
	bool mDKeyDown = false;
	bool mSpaceKeyDown = false;
};