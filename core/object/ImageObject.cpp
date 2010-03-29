#include "ImageObject.h"
using namespace Core;
using namespace Object;

std::map<std::string, sf::Image> ImageObject::s_images;

ImageObject::ImageObject()
	{

	}


ImageObject::~ImageObject() {}


sf::Image& ImageObject::getImage(const std::string& path)
	{
	//Load the image if it isn't already loaded
	if(s_images.find(path) == s_images.end())
		{
		s_images[path].LoadFromFile(path);
		}
	return s_images[path];
	}
