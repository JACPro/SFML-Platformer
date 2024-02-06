#include "Window.h"

Window::Window(uint32_t width, uint32_t height, const sf::String& title)
	: mWindow(sf::VideoMode(width, height), title)
{
	// Enable Vsync and lock FPS to 60
	mWindow.setVerticalSyncEnabled(true);
	mWindow.setFramerateLimit(60);

	// Create camera view for this window
	sf::View view(
		sf::Vector2f(0.0f, 0.0f), // Center
		sf::Vector2f((float)width, (float)height)); // Size
	mWindow.setView(view);

	// Create render texture for this window
	mRenderTex.create(width, height);
	mRenderTex.setView(view);
}

void Window::Clear()
{
	mWindow.clear();
	mRenderTex.clear();
}

void Window::Display()
{
	mWindow.display();
}

/*
* @brief Polls and handles window events
* @return Whether the Window is still open
*/
bool Window::HandleEvents()
{
	sf::Event event;

	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			mWindow.close();
		}
		else if (event.type == sf::Event::Resized)
		{
			sf::Vector2u size = sf::Vector2u(event.size.width, event.size.height);

			mWindow.setSize(size);

			sf::View view(
				sf::Vector2f(0.0f, 0.0f), // Center
				sf::Vector2f((float)size.x, (float)size.y)); // Size
			mWindow.setView(view);

			// Recreate render texture (cannot be resized)
			mRenderTex.create(size.x, size.y);
			mRenderTex.setView(view);
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				mWindow.close();
			}
			else
			{
				mInputHandler.PressButton(event.key.code);
			}
		}
	}

	return mWindow.isOpen();
}
