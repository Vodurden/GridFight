#ifndef GRIDFIGHT_CORE_GAME_H
#define GRIDFIGHT_CORE_GAME_H
//Extra Libs
#include <SFML/Graphics.hpp>

//STD
#include <map>
#include <iostream>
#include <string>

//Internal
#include "BaseState.h"
#include "state/MainMenu.h"
#include "state/Quit.h"
#include "../interface/SFMLController.h"
#include "../interface/ButtonFactory.h"
#include "../utility/ModuleManager.h"

namespace Core
	{
	class Game
		{
		public:
			Game();
			~Game();

			void run();

			void setState(const std::string& name);

			void addState(State::BaseState* state);

			sf::RenderWindow& getRenderWindow();
		private:
			bool stateExists(const std::string& name);

			std::string m_currentState;
			std::map<std::string, State::BaseState*> m_states;

			sf::RenderWindow m_window;

			Interface::SFMLController m_playerControl;

			static const std::string s_defaultState;
		};
	}
#endif
