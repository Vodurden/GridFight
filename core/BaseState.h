#ifndef GRIDFIGHT_CORE_BASESTATE_H
#define GRIDFIGHT_CORE_BASESTATE_H
#include <SFML/Graphics.hpp>
#include <string>
#include "../interface/BaseController.h"
namespace Core
	{
	namespace State
		{
		class BaseState
			{
			public:
				BaseState(const std::string& name);
				virtual ~BaseState();
				virtual void update() = 0;
				virtual void render(sf::RenderTarget& target);
				virtual std::string getName() const;
				virtual std::string getCurrentState() const;
				virtual void setCurrentState(const std::string& state);
			private:
				//Used to observe if the state needs to change
				std::string m_name;
				std::string m_currentState;
			};
		}
	}
#endif
