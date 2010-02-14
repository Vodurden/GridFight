#ifndef GRIDFIGHT_UTILITY_CONFIG_H
#define GRIDFIGHT_UTILITY_CONFIG_H
#include <libconfig.h++>
#include <tr1/memory>
#include <fstream>
#include <iostream>
namespace Utility
	{
	/**
	 * \brief Accesses libconfig standard configuration files.
	 *
	 * Encapsulates libconfig::Config to allow multiple classes to access
	 * the same file at the same time
	 */
	class Config
		{
		public:
			/**
			 * Default constructor, this class will not function 
			 * correctly untill setConfigFile is called
			 */
			Config();

			/**
			 * Loads config_file according to the libconfig standards
			 * an invalid file will not throw an error untill
			 * Config::lookup is called.
			 */
			Config(const std::string& config_file);

			/**
			 * Copy Constructor.
			 */
			Config(const Config& other);

			/**
			 * Chooses the file to look up configuration
			 * settings from
			 */
			void setConfigFile(const std::string& config_file);

			/**
			 * Returns a setting containing the value from 
			 * the configuration file according to libconfig standards
			 * 
			 * Assumes that config_file is a valid file
			 * Assumes that config_file has valid syntax.
			 *
			 * For example in a file:
			 * \code
			 *	application:
			 *		{
			 *		int = 1;
			 *		};
			 * \endcode
			 *
			 * The string "application.int" will return 1
			 * for more information consult the libconfig documentation at:
			 * http://www.hyperrealm.com/libconfig/libconfig_manual.html
			 */
			libconfig::Setting& lookup(const std::string& lookup_string);
		private:
			static std::map<std::string, std::tr1::shared_ptr<libconfig::Config> > m_configs;	
			std::string m_configFilePath;

			/**
			 * Loads a config file if fileIsLoaded(file_path) returns false
			 * required for Config::lookup to work.
			 *
			 * Automatically called by Config::Config.
			 */
			void loadConfigFile(const std::string& file_path);

			/**
			 * Checks if the data from the file located at "file_path" 
			 * has already been parsed and stored in m_configs
			 */
			bool fileIsLoaded(const std::string& file_path);
		};
	}
#endif
