#include "World.h"

World::World(Window& window)
	: mInputHandler(window.GetInputHandler())
{
}

bool World::LoadResources()
{
	return true;
}

void World::Update(float deltaTime)
{
}

void World::Render()
{
}

void World::Shutdown()
{
}

bool World::AddInputListener(InputComponent* listener)
{
	return mInputHandler.AddListener(listener);
}

void World::RemoveInputListener(InputComponent* listener)
{
	mInputHandler.RemoveListener(listener);
}
