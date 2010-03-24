#include "Config.h"
using namespace Utility;

std::map<std::string, std::tr1::shared_ptr<libconfig::Config> > Config::m_configs;

Config::Config() :
	m_errorState(false)
	{
	
	}

Config::Config(const std::string& file) :
	m_configFilePath(file)
	{
	loadConfigFile(file);
	}


Config::Config(const Config& other) :
	m_configFilePath(other.m_configFilePath)
	{
	
	}


void Config::setConfigFile(const std::string& config_file)
	{
	m_configFilePath = config_file;
	loadConfigFile(config_file);
	}


libconfig::Setting& Config::lookup(const std::string& lookup_string) const
	{
#ifndef NDEBUG
	std::cerr << "Looking up data: " << lookup_string << std::endl;
#endif
	return m_configs[m_configFilePath]->lookup(lookup_string);
	}


void Config::loadConfigFile(const std::string& file_path)
	{
	if(!fileIsLoaded(file_path))
		{
#ifndef NDEBUG
		std::cerr << "Loading config file: " << file_path << std::endl;
#endif
		std::ifstream file_stream(file_path.c_str());
		if(!file_stream.is_open())
			{
			std::cerr << "Error opening file: " << file_path << std::endl;
			}

		std::string data;
		char character;
		while(file_stream.get(character))
			{
			data += character;
			}

		std::tr1::shared_ptr<libconfig::Config> temp(new libconfig::Config());
		if(ConfigValidator::configIsValid(file_path))
			{
			temp->readString(data.c_str());
			}
		else
			{
			std::cerr << "Configuration File Error: " << std::endl <<
				"File: " << ConfigValidator::getErrorFile() << std::endl <<
				"Line: " << ConfigValidator::getErrorLine() << std::endl <<
				"Type: " << ConfigValidator::getErrorText() << std::endl;
			}
		m_configs[file_path] = temp;
		}
	}


bool Config::fileIsLoaded(const std::string& file_path)
	{
	return ( m_configs.find(file_path) != m_configs.end() );
	}

