#ifndef GRIDFIGHT_CORE_OBJECT_BASEUNIT_H
#define GRIDFIGHT_CORE_OBJECT_BASEUNIT_H
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "../../utility/Point.h"
#include "../../utility/Module.h"
#include "../../utility/Config.h"
#include "ImageObject.h"
namespace Core
	{
	namespace Object
		{
		class BaseUnit : public ImageObject
			{
			public:
				BaseUnit();

				virtual ~BaseUnit() = 0;

				virtual bool isColliding(BaseUnit& other) = 0;

				virtual void setPosition(Utility::iPoint pos) = 0;
				
				virtual void setSize(Utility::iPoint pos) = 0;

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

				virtual void update() = 0;

				virtual void render(sf::RenderTarget& target) = 0;
			};
		}
	}
#endif
