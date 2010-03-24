#ifndef GRIDFIGHT_CORE_OBJECT_BASEUNIT_H
#define GRIDFIGHT_CORE_OBJECT_BASEUNIT_H
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "../../utility/Point.h"
#include "../../utility/Module.h"
#include "../../utility/Config.h"
namespace Core
	{
	namespace Object
		{
		class BaseUnit
			{
			public:
				BaseUnit();

				virtual ~BaseUnit() = 0;

				virtual bool isColliding(BaseUnit& other) = 0;

				/**
				 * Returns the position
				 * in grid coordinates
				 */
				virtual Utility::iPoint getPosition() = 0;

				/**
				 * Returns the units
				 * size in grid
				 * spaces
				 */
				virtual Utility::iPoint getSize() = 0;

				virtual void alignToGrid(Utility::fPoint gridTileSize) = 0;

				virtual void update() = 0;

				virtual void render(sf::RenderTarget& target) = 0;
			protected:
				static sf::Image& getImage(const std::string& path);
			private:
				/**
				 * Image managing functions
				 */
				static std::map<std::string, sf::Image> s_images;
			};
		}
	}
#endif
