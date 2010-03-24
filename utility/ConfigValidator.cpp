#include "ConfigValidator.h"
using namespace Utility;

std::string ConfigValidator::s_config_error_file("");
std::string ConfigValidator::s_config_error_line("");
std::string ConfigValidator::s_config_error_text("");

bool ConfigValidator::configIsValid(const std::string& file)
	{
	config_t config;

	config_init(&config);

	if(! config_read_file(&config, file.c_str()))
		{
		s_config_error_file = config_error_file(&config);
		s_config_error_line = config_error_line(&config);
		s_config_error_text = config_error_text(&config);
		config_destroy(&config);
		return false;
		}

	return true;
	}

const std::string& ConfigValidator::getErrorFile()
	{
	return s_config_error_file;
	}

const std::string& ConfigValidator::getErrorLine()
	{
	return s_config_error_line;
	}

const std::string& ConfigValidator::getErrorText()
	{
	return s_config_error_text;
	}
