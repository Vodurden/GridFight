#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Module_Test
#include <string>
#include <boost/test/unit_test.hpp>
#include "../../utility/Module.h"
#include "../../utility/ModuleManager.h"
void CheckModuleCorrectSettings(const Utility::Module& test_module);

BOOST_AUTO_TEST_CASE( check_module_definitions )
	{
	Utility::Module test_module("module_dir/test_module");
	CheckModuleCorrectSettings(test_module);
	}

BOOST_AUTO_TEST_CASE( check_module_manager_module_get )
	{
	Utility::ModuleManager::SetModuleSearchPath("module_dir");
	Utility::Module& test_module = Utility::ModuleManager::GetModuleByName("test_module");
	CheckModuleCorrectSettings(test_module);	
	}

BOOST_AUTO_TEST_CASE( check_default_module_load )
	{
	Utility::ModuleManager::SetModuleSearchPath("module_dir");
	std::string default_path = Utility::ModuleManager::GetDefaultModuleName();
	Utility::Module& default_module = Utility::ModuleManager::GetModuleByName(default_path);
	CheckModuleCorrectSettings(default_module);
	}

void CheckModuleCorrectSettings(const Utility::Module& test_module)
	{
	BOOST_CHECK_EQUAL(test_module.getName(), "My Test Module");
	BOOST_CHECK_EQUAL(test_module.getVersion(), "1.0");
	BOOST_CHECK_EQUAL(test_module.getGraphicDir(), "graphics");
	BOOST_CHECK_EQUAL(test_module.getGroupDefinition(), "groups.cfg");
	BOOST_CHECK_EQUAL(test_module.getUnitDefinition(), "units.cfg");
	BOOST_CHECK_EQUAL(test_module.getInterfaceDefinition(), "interface.cfg");
	BOOST_CHECK_EQUAL(test_module.getGameDefinition(), "game.cfg");
	}
