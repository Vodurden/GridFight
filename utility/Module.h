#ifndef GRIDFIGHT_UTILITY_MODULE_H
#define GRIDFIGHT_UTILITY_MODULE_H
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
			Module(const std::string& path);
			~Module();
		private:

		};
	};
#endif
