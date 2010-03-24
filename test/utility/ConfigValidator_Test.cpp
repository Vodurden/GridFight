#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Config_Test
#include <boost/test/unit_test.hpp>
#include <iostream>

#include "../../utility/ConfigValidator.h"

BOOST_AUTO_TEST_CASE( correct_format_check )
	{
	BOOST_CHECK_EQUAL(Utility::ConfigValidator::configIsValid("module_dir/test_module/error_module.cfg"), false);
	std::cerr << "ErrorFile: " << Utility::ConfigValidator::getErrorFile() << std::endl;
	std::cerr << "ErrorLine: " << Utility::ConfigValidator::getErrorLine() << std::endl;
	std::cerr << "ErrorText: " << Utility::ConfigValidator::getErrorText() << std::endl;

	BOOST_CHECK_EQUAL(Utility::ConfigValidator::configIsValid("module_dir/test_module/module.cfg"), true);
	}
