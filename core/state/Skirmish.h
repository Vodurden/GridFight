#ifndef GRIDFIGHT_CORE_STATE_SKIRMISH_H
#define GRIDFIGHT_CORE_STATE_SKIRMISH_H
#include "Battle.h"
#include "../object/GroupFactory.h"
#include "../object/Group.h"
#include "../../utility/Point.h"
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
				std::vector<Object::Group*> m_units;
			};
		}
	}
#endif
