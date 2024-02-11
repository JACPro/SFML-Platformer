#pragma once

#include <SFML/Graphics.hpp>

struct Textures
{
	sf::Texture mPlayerTex;
};

class ResourceManager
{
public:
	ResourceManager() { }
	virtual ~ResourceManager() { }

	const Textures& GetTextures() const { return mTextures; }

	bool Load();
	bool LoadTextures();

private:
	Textures mTextures;
	// TODO add resource variables
};
