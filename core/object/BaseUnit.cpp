#include "BaseUnit.h"
using namespace Core;
using namespace Object;

BaseUnit::BaseUnit()
	{

	}


// Static Stuff
std::map<std::string, sf::Image> BaseUnit::s_images;

sf::Image& BaseUnit::getImage(const std::string& path)
	{
	// Load the image if it isn't already loaded
	if(s_images.find(path) == s_images.end())
		{
		s_images[path].LoadFromFile(path);
		}
	return s_images[path];
	}
