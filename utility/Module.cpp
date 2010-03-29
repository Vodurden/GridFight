#include "Module.h"
using namespace Utility;

Module::Module(const std::string& path) :
	m_config(path + "/module.cfg"),
	m_path(path)
	{
	
	}

Module::~Module()
	{

	}

std::string Module::getName() const
	{
	return get<const char*>("name");
	}

std::string Module::getVersion() const
	{
	return get<const char*>("version");
	}

std::string Module::getGraphicDir() const
	{
	return get<const char*>("graphic_dir");
	}

std::string Module::getGroupDefinition() const
	{
	return get<const char*>("group_definitions");
	}

std::string Module::getUnitDefinition() const
	{
	return get<const char*>("unit_definitions");
	}

std::string Module::getInterfaceDefinition() const
	{
	return get<const char*>("interface_definitions");
	}

std::string Module::getGameDefinition() const
	{
	return get<const char*>("game_definitions");
	}

std::string Module::getButtonDefinition() const
	{
	return get<const char*>("button_definitions");
	}

std::string Module::getGridDefinition() const
	{
	return get<const char*>("grid_definitions");
	}

std::string Module::getTypeDefinition() const
	{
	return get<const char*>("type_definitions");
	}

Config Module::getConfigFile(const std::string& name)
	{
	return m_path + "/" + name;
	}

std::string Module::getRelativePath() const
	{
	return m_path;
	}
