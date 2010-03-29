#ifndef GRIDFIGHT_UTILITY_MODULE_H
#define GRIDFIGHT_UTILITY_MODULE_H
#include <string>
#include "Config.h"
namespace Utility
	{
	/**
	 * Module's encapsulate access to a file-system folder
	 * that contains data specific to the game.
	 *
	 * A module folder must have the following file structure:
	 * \code
	 * 	module.cfg
	 *	${graphic_dir}
	 *	${group_definitions}
	 *	${unit_definitions}
	 *	${interface_definition}
	 *	${game_definitions}
	 * \endcode
	 * ( ${KEY} denotes a value in module.cfg )
	 *
	 *
	 * module.cfg uses the following format:
	 * \code
	 * module:
	 *	{
	 *	name = "My Test Module";
	 *	version = 1.0;
	 *	graphic_dir = "graphics";
	 *	group_definitions = "groups.cfg";
	 *	unit_definitions = "units.cfg";
	 *	interface_definitions = "interface.cfg";
	 *	game_definitions = "game.cfg";
	 *	};
	 * \endcode
	 */
	class Module
		{
		public:
			/**
			 * Constructor
			 *
			 * path should be a folder, containing a module.cfg
			 */
			Module(const std::string& path);

			/**
			 * Deconstructor
			 */
			~Module();

			std::string getName() const;
			std::string getVersion() const;
			std::string getGraphicDir() const;
			std::string getGroupDefinition() const;
			std::string getUnitDefinition() const;
			std::string getInterfaceDefinition() const;
			std::string getGameDefinition() const;
			std::string getButtonDefinition() const;
			std::string getGridDefinition() const;
			std::string getTypeDefinition() const;

			std::string getRelativePath() const;

			Config getConfigFile(const std::string& name);
		private:
			Config m_config;

			std::string m_path;

			template <typename return_val>
			return_val get(const std::string& key_name) const
				{
				return static_cast<return_val>(
					m_config.lookup(std::string("module.") + key_name));
				}

		};
	}
#endif
