#include "ModuleManager.h"
using namespace Utility;

std::map<std::string, std::tr1::shared_ptr<Module> > ModuleManager::m_modules;
std::string ModuleManager::m_moduleSearchPath;
bool ModuleManager::m_modulePathSearched = false;


void ModuleManager::SetModuleSearchPath(const std::string& path)
	{
	if( !boost::filesystem::exists(path) )
		{
		std::cerr << "Error loading module search path (file does not exist): " 
			<< path << std::endl;
		return;
		}

	m_modulePathSearched = true;
	m_moduleSearchPath = path;
	
	boost::filesystem::directory_iterator end_itr;
	for( boost::filesystem::directory_iterator itr( path ); itr != end_itr; ++itr)
		{
		if(boost::filesystem::is_directory( *itr) )
			{

			ModulePtr module( new Utility::Module(m_moduleSearchPath + "/" +  itr->leaf()) );
			m_modules[m_moduleSearchPath + "/" + itr->leaf()] = module;
			}
		}
	}


Module& ModuleManager::GetModuleByName(const std::string& name)
	{
	if(m_modules.find(m_moduleSearchPath + "/" + name) == m_modules.end())
		{
		std::cerr << "Error loading module at name: " << name << std::endl;
		}
	return *m_modules[m_moduleSearchPath + "/" + name];
	}

Module& ModuleManager::GetDefaultModule()
	{
	return GetModuleByName(GetDefaultModuleName());
	}

std::string ModuleManager::GetDefaultModuleName()
	{
	Config conf(m_moduleSearchPath + "/module.cfg");
	return static_cast<const char*>(conf.lookup("module.default"));
	}
