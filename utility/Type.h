#ifndef GRIDFIGHT_UTILITY_TYPE_H
#define GRIDFIGHT_UTILITY_TYPE_H
#include "ModuleManager.h"
#include "Module.h"
#include "Config.h"
#include "../interface/Color.h"
namespace Utility
	{
	class Type
		{
		public:
			Type();
			Type(const std::string& name);
			~Type();

			Interface::Color getColor() const;
			void setColor(Interface::Color color);
		private:
			Interface::Color m_color;
		};
	}
#endif
