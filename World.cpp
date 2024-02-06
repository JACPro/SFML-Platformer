#include "World.h"
#include "Player.h"

World::World(Window& window)
	: mWindow(window)
	, mInputHandler(window.GetInputHandler())
{
}

bool World::LoadResources()
{
	return true;
}

void World::Update(float deltaTime)
{
	UpdateEntities(deltaTime);
}

void World::Render()
{
	RenderEntities();
}

void World::Shutdown()
{
	DestroyAllEntities();
}

bool World::AddInputListener(InputComponent* listener)
{
	return mInputHandler.AddListener(listener);
}

void World::RemoveInputListener(InputComponent* listener)
{
	mInputHandler.RemoveListener(listener);
}

void World::UpdateEntities(float deltaTime)
{
	for (Entity* entity : mEntities)
	{
		if (entity != nullptr && entity->IsEnabled())
		{
			entity->Update(deltaTime);
		}
	}

	for (auto it = mEntities.begin(); it < mEntities.end();)
	{
		if (Entity* entity = *it)
		{
			Actor* actor = dynamic_cast<Actor*>(entity);
			if (actor)				
			{
				if (actor->IsDead())
				{
					actor->Destroy();

					if (actor == mPlayer)
					{
						mPlayer = nullptr;
					}

					delete actor;
					it = mEntities.erase(it);
				}
				else
				{
					++it;
				}
			}
			else
			{
				++it;
			}
		}
		else
		{
			it = mEntities.erase(it);
		}
	}
}

void World::RenderEntities()
{
	for (Entity* entity : mEntities)
	{
		if (entity != nullptr)
		{
			entity->Render(mWindow.GetRenderTex());
		}
	}
}

void World::DestroyAllEntities()
{
	for (Entity* entity : mEntities)
	{
		delete entity;
	}

	mEntities.clear();
}
