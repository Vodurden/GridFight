#include "Utility.h"

std::vector<std::string> Utility::splitString( 
	const std::string& string,
	const std::string& delimier)
	{
	boost::char_separator<char> seperator("\n");
	boost::tokenizer<boost::char_separator<char> > tokens(string, seperator);
	return std::vector<std::string>(tokens.begin(), tokens.end());
	}


size_t Utility::findLastWordPosition(
	const std::string& string,
	float maximumSize,
	sf::Font font,
	float size) 
	{
	size_t returnPos = 0;
	sf::String testString(string, font, size);

	for(unsigned int charPos = 0; charPos < string.length(); ++charPos)
		{
		float length = (testString.GetCharacterPos(charPos) - testString.GetCharacterPos(0)).x;

		if(length > maximumSize)
			{
			break;
			}

		if(string.at(charPos) == ' ')
			{
			returnPos = charPos;
			}
		}
	
	return returnPos;
	}

float Utility::findXAlignment(
	Interface::POSITION_TYPE type,
	Utility::fPoint start_position,
	Utility::fPoint start_size,
	const std::string& string)
	{
	switch(type)
		{
		case Interface::Position_Left:
			return start_position.getX();
		case Interface::Position_Center:
			return (start_position.getX() + (start_size.getX() / 2)) - (Utility::getLengthInPixels(string) / 2);
		case Interface::Position_Right:
			return (start_position.getX() + start_size.getX() - Utility::getLengthInPixels(string));
		default:
			return 0.0f;
		}
	}
