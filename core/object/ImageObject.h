#ifndef GRIDFIGHT_CORE_OBJECT_IMAGEOBJECT_H
#define GRIDFIGHT_CORE_OBJECT_IMAGEOBJECT_H
#include <SFML/Graphics.hpp>
#include <string>
namespace Core
	{
	namespace Object
		{
		class ImageObject
			{
			public:
				ImageObject();

				virtual ~ImageObject() = 0;
			protected:
				static sf::Image& getImage(const std::string& path);
			private:
				static std::map<std::string, sf::Image> s_images;
			};
		}
	}
#endif
