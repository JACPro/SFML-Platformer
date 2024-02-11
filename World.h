#pragma once

#include "Window.h"
#include "ResourceManager.h"

class InputHandler;
class Player;
class Entity;

class World
{
public:
	explicit World(Window& window);

	bool Load();
	void Update(float deltaTime);
	void Render();
	void Shutdown();

	// Input handling
	bool AddInputListener(InputComponent* listener);
	void RemoveInputListener(InputComponent* listener);

	const ResourceManager& GetResources() const { return mResourceManager; }
	sf::RenderTexture& GetRenderTex() const { return mWindow.GetRenderTex(); }

private:
	Window& mWindow;
	ResourceManager mResourceManager;

	sf::Vector2f(mCameraPos);

	template<typename T>
	T* SpawnEntity()
	{
		if (T* entity = new T(*this))
		{
			mEntities.push_back(entity);
			return entity;
		}
		else
		{
			printf("ERROR: Failed to spawn entity\r\n");
			return nullptr;
		}
	}

	void UpdateEntities(float deltaTime);
	void RenderEntities();
	void DestroyAllEntities();

	void UpdateCamera(float deltaTime);

	InputHandler& mInputHandler;

	Player* mPlayer = nullptr;
	std::vector<Entity*> mEntities;
};