#ifndef GRIDFIGHT_CORE_OBJECT_GROUPFACTORY_H
#define GRIDFIGHT_CORE_OBJECT_GROUPFACTORY_H
#include <string>

#include "Group.h"
#include "ConfigUnit.h"
#include "../../utility/ModuleManager.h"
#include "../../utility/Module.h"
#include "../../utility/Config.h"
namespace Core
	{
	namespace Object
		{
		class GroupFactory
			{
			public:
				/**
				 * Returns a group from the
				 * default module
				 * based on the group
				 * configuration file
				 */
				static Group* getGroup(const std::string& name, Utility::fPoint gridTileSize);
			};
		}
	}
#endif
