#ifndef GRIDFIGHT_CORE_STATE_BATTLE_H
#define GRIDFIGHT_CORE_STATE_BATTLE_H
#include <SFML/Graphics.hpp>
#include <string>
#include "../BaseState.h"
#include "../interface/BaseController.h"
namespace Core
	{
	namespace State
		{
		class Battle : public BaseState
			{
			public:
				Battle(
					const std::string& name, 
					BaseController& controlA, 
					BaseController& controlB
					);

				virtual ~Battle() = 0;

				virtual void update() = 0;

				virtual void render(sf::RenderTarget& target) = 0;
			private:
				BaseController& m_controllerA;
				BaseController& m_controllerB;
			};
		}
	}
#endif
