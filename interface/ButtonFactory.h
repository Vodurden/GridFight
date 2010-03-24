#ifndef GRIDFIGHT_INTERFACE_BUTTONFACTORY_H
#define GRIDFIGHT_INTERFACE_BUTTONFACTORY_H
#include <string>
#include <map>
#include <tr1/memory>
#include <SFML/Graphics.hpp>
#include <boost/filesystem.hpp>
#include <cassert>
#include "Button.h"
#include "ImageButton.h"
#include "TextRectButton.h"
#include "../utility/ModuleManager.h"
#include "../utility/Point.h"
#include "../utility/Module.h"
#include "../utility/Config.h"
namespace Interface
	{
	class ButtonFactory
		{
		public:
			static Button* getButton(const std::string& name);

			static void addRelativePosition(const std::string& name, Utility::fPoint point);
		private:
			static void loadImage(const std::string& name);

			static std::string loadConfigImage(
				const std::string& name, 
				Utility::Module& module,
				const Utility::Config& conf,
				const std::string& lookup_type
				);

			static Utility::fPoint getRelativePosition(const std::string& name);

			static std::tr1::shared_ptr<sf::Image> getImage(const std::string& path);

			static std::map<std::string, std::tr1::shared_ptr<sf::Image> > m_images;

			static std::map<std::string, Utility::fPoint> m_relativePositions;
		};
	}
#endif
