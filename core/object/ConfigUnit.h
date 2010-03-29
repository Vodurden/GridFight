#ifndef GRIDFIGHT_CORE_OBJECT_CONFIGUNIT
#define GRIDFIGHT_CORE_OBJECT_CONFIGUNIT
#include <SFML/Graphics.hpp>
#include "BaseUnit.h"
#include "../../utility/Point.h"
#include "../../utility/Module.h"
#include "../../utility/ModuleManager.h"
#include "../../utility/Config.h"
#include "../../utility/Type.h"
namespace Core
	{
	namespace Object
		{
		class ConfigUnit : public BaseUnit
			{
			public:
				ConfigUnit(const std::string& name, const Utility::fPoint gridTileSize);

				~ConfigUnit();

				Utility::iPoint getPosition();

				Utility::iPoint getSize();

				Utility::Type getType();

				void setPosition(Utility::iPoint pos);

				void setSize(Utility::iPoint size);

				void setOffset(Utility::fPoint offset);

				bool isColliding(BaseUnit& other);

				void update();

				void render(sf::RenderTarget& target);
			private:
				sf::Sprite m_sprite;	

				Utility::Type m_type;
				Utility::iPoint m_pos;
				Utility::iPoint m_size;
				Utility::fPoint m_offset;

				Utility::fPoint m_gridTileSize;

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
