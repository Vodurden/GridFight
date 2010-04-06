#include "SFMLUtility.h"

unsigned int Utility::getLengthInPixels(
	const std::string& text,
	const sf::Font& font,
	float size)
	{
	sf::String testString(text, font, size);
	return ( testString.GetCharacterPos(text.length()) - testString.GetCharacterPos(0)).x;
	}
