#ifndef GRIDFIGHT_UTILITY_SFMLUTILITY_H
#define GRIDFIGHT_UTILITY_SFMLUTILITY_H
#include <SFML/Graphics.hpp>
namespace Utility
	{
	unsigned int getLengthInPixels(
		const std::string& text,
		const sf::Font& font = sf::Font::GetDefaultFont(),
		float size = 30.f
		);
	}
#endif
