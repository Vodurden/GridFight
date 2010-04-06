#ifndef GRIDFIGHT_CORE_STATE_SKIRMISH_H
#define GRIDFIGHT_CORE_STATE_SKIRMISH_H
#include "Battle.h"
#include "../object/GroupFactory.h"
#include "../object/Group.h"
#include "../object/Grid.h"
#include "../../utility/Point.h"
#include "../../interface/FormattedTextArea.h"
namespace Core
	{
	namespace State
		{
		class Skirmish : public Battle
			{
			public:
				Skirmish(Interface::BaseController& controlA, Interface::BaseController& controlB);

				virtual ~Skirmish();

				void update();
				
				void render(sf::RenderTarget& target);
			private:
				Object::Grid m_grid;
			};
		}
	}
#endif
