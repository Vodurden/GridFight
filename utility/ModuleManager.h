#ifndef GRIDFIGHT_UTILITY_MODULEMANAGER_H
#define GRIDFIGHT_UTILITY_MODULEMANAGER_H
#include "Module.h"
#include "Config.h"
#include <iostream>
#include <tr1/memory>
#include <boost/filesystem.hpp>
namespace Utility
	{
	/**
	 * Utility Class to load a Module class from
	 * module folders.
	 */
	class ModuleManager
		{
		public:
			/**
			 * Sets the folder that contains all other module
			 * folders.
			 */
			static void SetModuleSearchPath(const std::string& path);		

			/**
			 * Loads a module from the ModuleSearchPath 
			 * returns a Module initialized with the path
			 * to the module.
			 */
			static Module& GetModuleByName(const std::string& name);	

			/**
			 * Gets the default module name
			 * based on module.cfg in the base
			 * module search path
			 */
			 static std::string GetDefaultModuleName();

			/**
			 * Gets the default module
			 */
			 static Module& GetDefaultModule();
		private:
			typedef std::tr1::shared_ptr<Module> ModulePtr;

			static std::map<std::string, ModulePtr > m_modules;

			static std::string m_moduleSearchPath;

			static bool m_modulePathSearched;
		};
	}
#endif
