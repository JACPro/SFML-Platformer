#pragma once

#include <cmath>
#include <SFML/Window.hpp>

//TODO should MathFunctions become a namespace?

template<typename T>
static sf::Vector2<T> Normalize(const sf::Vector2<T> vec)
{
	// magnitude = sqrt of the sum of the squares of each dimension in the vector
	float magnitude = sqrt(vec.x * vec.x + vec.y * vec.y);
	if (magnitude <= FLT_EPSILON)
	{
		return sf::Vector2<T>(0.0f, 0.0f); // let's not divide by zero today
	}
	else
	{
		// to get the unit vector, simply divide each dimension value by the magnitude
		return sf::Vector2<T>(vec.x / magnitude, vec.y / magnitude);
	}
}
