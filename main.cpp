#include <SFML/Graphics.hpp>
#include "Window.h"

int main()
{
	// Seed random with the current time
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	Window	  window(1920, 1080, "SFML PLATFORMER");
	World world(window);

	if (world.LoadResources())
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

	world.Shutdown();

	return 0;
}