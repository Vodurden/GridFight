#include "GroupFactory.h"
using namespace Core;
using namespace Object;

Group* GroupFactory::getGroup(const std::string& name, Utility::fPoint gridTileSize)
	{
	Utility::Module module = Utility::ModuleManager::GetDefaultModule();
	const Utility::Config& config = module.getConfigFile(module.getGroupDefinition());

	Group* group = new Group();

	libconfig::Setting& layout = config.lookupf<libconfig::Setting&>("group", name, "layout");

	for(int index = 0; index < layout.getLength(); ++index)
		{
		libconfig::Setting& layoutSetting = layout[index];
		group->addUnit(
			Utility::iPoint(static_cast<int>(layoutSetting[1]), static_cast<int>(layoutSetting[2])),
			new ConfigUnit(static_cast<const char*>(layoutSetting[0]), gridTileSize)
			);
		group->update();
		}
	
	return group;
	}
