#ifndef GRIDFIGHT_UTILITY_CONFIGVALIDATOR_H
#define GRIDFIGHT_UTILITY_CONFIGVALIDATOR_H
#include <libconfig.h>
#include <string>
namespace Utility
	{
	class ConfigValidator
		{
		public:
			static bool configIsValid(const std::string& file);

			static const std::string& getErrorFile();
			static const std::string& getErrorLine();
			static const std::string& getErrorText();
		private:
			static std::string s_config_error_file;
			static std::string s_config_error_line;
			static std::string s_config_error_text;
		};
	}
#endif
