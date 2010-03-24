#ifndef GRIDFIGHT_CORE_OBJECT_CONFIGUNIT
#define GRIDFIGHT_CORE_OBJECT_CONFIGUNIT
#include <SFML/Graphics.hpp>
#include "BaseUnit.h"
#include "../../utility/Point.h"
#include "../../utility/Module.h"
#include "../../utility/ModuleManager.h"
#include "../../utility/Config.h"
namespace Core
	{
	namespace Object
		{
		class ConfigUnit : public BaseUnit
			{
			public:
				ConfigUnit(const std::string& name);

				~ConfigUnit();

				Utility::iPoint getPosition();

				Utility::iPoint getSize();

				bool isColliding(BaseUnit& other);

				void alignToGrid(Utility::fPoint gridTileSize);

				void update();

				void render(sf::RenderTarget& target);
			private:
				sf::Sprite m_sprite;	

				Utility::iPoint m_pos;
				Utility::iPoint m_size;

				int m_health;
				int m_damage;
				int m_range;
				int m_defense;
				int m_attackSpeed;
				int m_moveSpeed;
			};
		}
	}
#endif
