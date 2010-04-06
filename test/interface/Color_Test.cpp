#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Config_Test
#include <boost/test/unit_test.hpp>

#include "../../interface/Color.h"
#include "../../utility/Config.h"

BOOST_AUTO_TEST_CASE( color_lookup_test )
	{
	Utility::Config config("test_config_file.cfg");
	Interface::Color color(config.lookupf<Interface::Color>("test", "color"));

	BOOST_CHECK_EQUAL( color.getR(), 255 );
	BOOST_CHECK_EQUAL( color.getG(), 255 );
	BOOST_CHECK_EQUAL( color.getB(), 255 );
	BOOST_CHECK_EQUAL( color.getA(), 255 );
	}
