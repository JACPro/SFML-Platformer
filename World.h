#pragma once

#include "Window.h"

class InputHandler;
class Player;
class Entity;

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
	Window& mWindow;

	void UpdateEntities(float deltaTime);
	void RenderEntities();
	void DestroyAllEntities();

	InputHandler& mInputHandler;

	Player* mPlayer = nullptr;
	std::vector<Entity*> mEntities;
};