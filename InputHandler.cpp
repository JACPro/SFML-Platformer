#include "InputHandler.h"
#include "InputComponent.h"
#include <algorithm>

#include <iostream>

/*
* I created this input handler at first because I thought I could feed the keyboard events retrieved 
* when we pollEvent on a window through it, then push those out to any listeners. When I output a 
* print statement on button press, I realised this was not going to work for my desired use case.
* 
* I decided to keep the InputHandler ultimately because it is a central place where I can control 
* the complete set of buttons that the game will handle. Any button not handled here will not be
* used in the game.
* If I knew of a way, I would like to make it impossible for any other class to read from 
* sf::Keyboard::isKeyPressed so I could guarantee all input comes through here. As the sole developer, 
* I can get away with choosing to feed all my input through here manually without any checks in place
* to prevent usage elsewhere
*/



/*
* @brief Add a listener to be notified when there is an input event
* @param listener The listener to add to the list
* @return false if listener already in list; true otherwise
*/
bool InputHandler::AddListener(InputComponent* listener)
{
	if (listener == nullptr)
	{
		return false;
	}

	// Listener is not already present in the list
	if (std::find(mListeners.begin(), mListeners.end(), listener) == mListeners.end())
	{
		mListeners.push_back(listener);
		listener->SetButtonStatusRef(&mButtonStatus);
		return true;
	}
	else
	{
		return false;
	}
}

/*
* @brief Add a listener to be notified when there is an input event
* @param listener The listener to add to the list
* @return false if listener already in list; true otherwise
*/
void InputHandler::RemoveListener(InputComponent* listener)
{
	if (listener != nullptr)
	{
		listener->ClearButtonStatusRef();
	}

	mListeners.remove(listener);
}

/*
* @brief Check whether a given button has just been pressed, released, or is currently held down
* @param key The button to test
* @param keyDownBool A boolean storing whether the button was down in the last update loop
*/
void InputHandler::CheckButton(sf::Keyboard::Key key, bool& keyDownBool)
{
	if (sf::Keyboard::isKeyPressed(key))
	{
		if (!keyDownBool)
		{
			OnKeyDown(key);
			keyDownBool = true;
		}
		else
		{
			OnKeyHeld(key);
		}
	}
	else
	{
		if (keyDownBool)
		{
			OnKeyUp(key);
			keyDownBool = false;
		}
	}
}

/*
* @brief Check the status of each relevant button to see if we need to handle input
*/
void InputHandler::Update(float deltaTime)
{
	CheckButton(sf::Keyboard::W, mButtonStatus.mWKeyDown);
	CheckButton(sf::Keyboard::A, mButtonStatus.mAKeyDown);
	CheckButton(sf::Keyboard::S, mButtonStatus.mSKeyDown);
	CheckButton(sf::Keyboard::D, mButtonStatus.mDKeyDown);
	CheckButton(sf::Keyboard::Space, mButtonStatus.mSpaceKeyDown);

	for (InputComponent* ic : mListeners)
	{
		ic->Update(deltaTime);
	}
}

/*
* @brief Notify all listeners that a button was just pressed down and pass that button as an argument
* @param key The button that was just pressed
*/
void InputHandler::OnKeyDown(sf::Keyboard::Key key)
{
	for (InputComponent* ic : mListeners)
	{
		if (ic != nullptr)
		{
			ic->OnKeyDown(key);
		}
		else
		{
			printf("Warning: Null InputComponent found in InputHandler; has been removed.");
			RemoveListener(ic);
		}
	}
}

/*
* @brief Notify all listeners that a button was just released and pass that button as an argument
* @param key The button that was just released
*/
void InputHandler::OnKeyUp(sf::Keyboard::Key key)
{
	for (InputComponent* ic : mListeners)
	{
		if (ic != nullptr)
		{
			ic->OnKeyUp(key);
		}
		else
		{
			printf("Warning: Null InputComponent found in InputHandler; has been removed.");
			RemoveListener(ic);
		}
	}
}

/*
* @brief Notify all listeners that a button is being held down and pass that button as an argument
* @param key The button that is being held
*/
void InputHandler::OnKeyHeld(sf::Keyboard::Key key)
{
	for (InputComponent* ic : mListeners)
	{
		if (ic != nullptr)
		{
			ic->OnKeyHeld(key);
		}
		else
		{
			printf("Warning: Null InputComponent found in InputHandler; has been removed.");
			RemoveListener(ic);
		}
	}
}
