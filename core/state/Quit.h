#ifndef GRIDFIGHT_CORE_STATE_QUIT_H
#define GRIDFIGHT_CORE_STATE_QUIT_H
#include <SFML/Graphics.hpp>
#include "../BaseState.h"
namespace Core
	{
	namespace State
		{
		class Quit : public BaseState
			{
			public:
				Quit(sf::RenderWindow& window);
				void update();
			private:
				sf::RenderWindow& m_window;
			};
		}
	}
#endif
