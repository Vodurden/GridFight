#ifndef GRIDFIGHT_UTILITY_TYPE_H
#define GRIDFIGHT_UTILITY_TYPE_H
#include "ModuleManager.h"
#include "Module.h"
#include "Config.h"
#include "Color.h"
namespace Utility
	{
	class Type
		{
		public:
			Type();
			Type(const std::string& name);
			~Type();

			Color getColor();
			void setColor(Color color);
		private:
			Color m_color;
		};
	}
#endif
