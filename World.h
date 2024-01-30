#pragma once
#include "Window.h"

class World
{
public:
	explicit World(Window& window);

	bool LoadResources();
	void Update(float deltaTime);
	void Render();
	void Shutdown();
private:
};