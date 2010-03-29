#ifndef GRIDFIGHT_CORE_OBJECT_GRID_H
#define GRIDFIGHT_CORE_OBJECT_GRID_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Group.h"
#include "ImageObject.h"
#include "../../utility/ModuleManager.h"
#include "../../utility/Module.h"
#include "../../utility/Config.h"
namespace Core
	{
	namespace Object
		{
		/**
		 * The grid is responsible
		 * for maintaining all groups
		 * and the relationships between
		 * groups
		 *
		 * Handles Collision and Movement, 
		 * Effects and Combat are handled
		 * by outside analysis
		 */
		class Grid : public ImageObject
			{
			public:
				Grid(const std::string& name);
				~Grid();

				void addGroup(Group* group);

				void update();

				void render(sf::RenderTarget& target);
			private:
				std::vector<Group*> m_groups;

				sf::Sprite m_gridbase;
				Utility::fPoint m_pos;
				Utility::iPoint m_size;
			};
		}
	}
#endif
