#include "World.h"
#include "Player.h"

World::World(Window& window)
	: mWindow(window)
	, mInputHandler(window.GetInputHandler())
{
}

bool World::Load()
{
	if (!mResourceManager.Load())
	{
		return false;
	}

	mPlayer = SpawnEntity<Player>();
	mCameraPos = mPlayer->GetPosition();
	
	return true;
}

void World::Update(float deltaTime)
{
	mInputHandler.Update();
	UpdateEntities(deltaTime);
	UpdateCamera(deltaTime);
}

void World::Render()
{
	RenderEntities();

	sf::Sprite fullScreenSprite(GetRenderTex().getTexture());

	const sf::Vector2f& viewSize = mWindow.GetRenderWindow().getView().getSize();
	fullScreenSprite.setOrigin(viewSize * 0.5f);
	fullScreenSprite.setScale(sf::Vector2f(1.0f, -1.0f));

	mWindow.GetRenderWindow().draw(fullScreenSprite);
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
				if (actor->GetHealthComponent().IsDead())
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
			entity->Render(GetRenderTex());
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

void World::UpdateCamera(float deltaTime)
{
	if (mPlayer != nullptr)
	{
		mCameraPos = mPlayer->GetPosition();
	}
}
