#include "ResourceManager.h"

/*
* @brief Load all required resources from file into memory
* @return true if all resources were loaded successfully, false otherwise
*/
bool ResourceManager::Load()
{
	bool success = true;

	success &= LoadTextures();

	return success;
}

bool ResourceManager::LoadTextures()
{
	bool success = true;

	Textures& t = mTextures;

	success &= t.mPlayerTex.loadFromFile("./Assets/Textures/Player.png");

	return success;
}
