#include "Config.h"
using namespace Utility;

std::map<std::string, std::tr1::shared_ptr<libconfig::Config> > Config::m_configs;

Config::Config() 
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


libconfig::Setting& Config::lookup(const std::string& lookup_string)
	{
	return m_configs[m_configFilePath]->lookup(lookup_string);
	}


void Config::loadConfigFile(const std::string& file_path)
	{
	if(!fileIsLoaded(file_path))
		{
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
		temp->readString(data.c_str());
		m_configs[file_path] = temp;
		}
	}


bool Config::fileIsLoaded(const std::string& file_path)
	{
	return ( m_configs.find(file_path) != m_configs.end() );
	}

