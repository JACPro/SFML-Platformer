#include "InputHandler.h"
#include "InputComponent.h"

InputHandler::InputHandler()
{
}

/*
* @brief Add a listener to be notified when there is an input event
* @param listener The listener to add to the list
* @return false if listener already in list; true otherwise
*/
bool InputHandler::AddListener(InputComponent* listener)
{
	// Listener is not already present in the list
	if (std::find(mListeners.begin(), mListeners.end(), listener) != mListeners.end())
	{
		mListeners.push_back(listener);
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
	mListeners.remove(listener);
}

/*
* @brief Notify all listeners that a button was pressed and pass that button as an argument
* @param button The button that was pressed
*/
void InputHandler::PressButton(sf::Keyboard::Key button)
{
	for (InputComponent* ic : mListeners)
	{
		if (ic != nullptr)
		{
			ic->HandleButtonPress(button);
		}
		else
		{
			printf("Warning: Null InputComponent found in InputHandler; has been removed.");
			RemoveListener(ic);
		}
	}
}
