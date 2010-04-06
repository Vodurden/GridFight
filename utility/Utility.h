#ifndef GRIDFIGHT_UTILITY_UTILITY_H
#define GRIDFIGHT_UTILITY_UTILITY_H
#include <boost/tokenizer.hpp>
#include <string>
#include "SFMLUtility.h"
#include "Point.h"
#include "../interface/Position.h"
namespace Utility
	{
	/**
	 * Splits "string" into parts based on
	 * the delimiter
	 */
	std::vector<std::string> splitString(
		const std::string& string,
		const std::string& delimier
		);
	
	/**
	 * Find the last whole word position within
	 * a string in a given range
	 */
	size_t findLastWordPosition(
		const std::string& string,
		float maxiumumSize,
		sf::Font font = sf::Font::GetDefaultFont(),
		float size = 30.0f
		);
	
	float findXAlignment(
		Interface::POSITION_TYPE type,
		Utility::fPoint start_position,
		Utility::fPoint start_size,
		const std::string& string
		);
	}
#endif
