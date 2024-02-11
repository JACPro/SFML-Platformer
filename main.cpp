#include <SFML/Graphics.hpp>
#include "Window.h"
#include "World.h"

int main()
{
	// Seed random with the current time
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	Window	  window(1920, 1080, "SFML PLATFORMER");
	World world(window);

	if (world.Load())
	{
		sf::Clock clock;

		while (window.HandleEvents())
		{
			sf::Time deltaTime = clock.getElapsedTime();
			clock.restart();

			window.Clear();

			world.Update(deltaTime.asSeconds());
			world.Render();

			window.Display();
		}
	}
	else
	{
		printf("ERROR: Failed to load resources\r\n");
	}

	world.Shutdown();

	return 0;
}
