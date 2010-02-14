#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Module_Test
#include <boost/test/unit_test.hpp>

#include "../../utility/Module.h"

BOOST_AUTO_TEST_CASE( set_path_and_load )
	{
	Utility::Module::SetModuleDir("module_dir");
	Utility::Module::LoadModule("test_module");
	}


BOOST_AUTO_TEST_CASE( get_module_path )
	{
	Utility::Module::SetModuleDir("module_dir");
	Utility::Module::LoadModule("test_module");

	BOOST_CHECK_EQUAL(Utility::Module::GetModulePath(), "module_dir");
	BOOST_CHECK_EQUAL(Utility::Module::GetModuleName(), "test_module");
	}


BOOST_AUTO_TEST_CASE( get_module_config )
	{
	Utility::Module::LoadModuleConfig("module_dir/test_module_file.cfg");

	BOOST_CHECK_EQUAL(Utility::Module::GetModulePath(), "module_dir");
	BOOST_CHECK_EQUAL(Utility::Module::GetModuleName(), "test_module");
	}
