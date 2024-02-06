#pragma once

#include <SFML/Graphics.hpp>
#include "InputHandler.h"

class Window
{
public:
	Window(uint32_t width, uint32_t height, const sf::String& title);

	void Clear();
	void Display();
	bool HandleEvents();

	sf::RenderWindow& GetRenderWindow() { return mWindow; }
	sf::RenderTexture& GetRenderTex() { return mRenderTex; }
	InputHandler& GetInputHandler() { return mInputHandler; }
	
private:
	sf::RenderWindow mWindow;
	sf::RenderTexture mRenderTex;

	InputHandler mInputHandler;
};