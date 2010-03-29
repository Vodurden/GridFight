#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Config_Test
#include <boost/test/unit_test.hpp>

#include <string>
#include <iostream>
#include "../../utility/Config.h"

void CheckLookups(Utility::Config& config);

BOOST_AUTO_TEST_CASE( constructor_test )
	{
	Utility::Config config("test_config_file.cfg");
	}

BOOST_AUTO_TEST_CASE( copy_constructor_test )
	{
	Utility::Config configA("test_config_file.cfg");
	Utility::Config configB(configA);
	CheckLookups(configB);
	}

BOOST_AUTO_TEST_CASE( resource_load_test )
	{
	Utility::Config config("test_config_file.cfg");
	CheckLookups(config);
	}

BOOST_AUTO_TEST_CASE( lookupf_test )
	{
	Utility::Config config("test_config_file.cfg");
	std::string check_string = config.lookupf<const char*>("test", "string");
	BOOST_CHECK_EQUAL( check_string, "Test string" );
	}

void CheckLookups(Utility::Config& config)
	{
	std::string check_string = static_cast<const char*>(config.lookup("test.string"));
	int check_int = static_cast<int>(config.lookup("test.int"));
	float check_float = static_cast<float>(config.lookup("test.float"));

	int r = static_cast<int>(config.lookup("test.color.r"));
	int g = static_cast<int>(config.lookup("test.color.g"));
	int b = static_cast<int>(config.lookup("test.color.b"));
	int a = static_cast<int>(config.lookup("test.color.a"));

	BOOST_CHECK_EQUAL( check_string, "Test string" );
	BOOST_CHECK_EQUAL( check_int, 5 );
	BOOST_CHECK_EQUAL( check_float, 2.5f );
	BOOST_CHECK_EQUAL( r, 255 );
	BOOST_CHECK_EQUAL( g, 255 );
	BOOST_CHECK_EQUAL( b, 255 );
	BOOST_CHECK_EQUAL( a, 255 );
	}
