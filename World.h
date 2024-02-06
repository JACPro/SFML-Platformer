#pragma once

#include "Window.h"

class InputHandler;

class World
{
public:
	explicit World(Window& window);

	bool LoadResources();
	void Update(float deltaTime);
	void Render();
	void Shutdown();

	// Input handling
	bool AddInputListener(InputComponent* listener);
	void RemoveInputListener(InputComponent* listener);

private:
	InputHandler& mInputHandler;
};