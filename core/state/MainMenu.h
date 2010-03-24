#ifndef GRIDFIGHT_CORE_MAINMENU_H
#define GRIDFIGHT_CORE_MAINMENU_H
#include "../BaseState.h"
#include "../../interface/BaseController.h"
#include "../../interface/Button.h"
#include "../../interface/ButtonFactory.h"
#include "../../system/Event.h"
#include "Menu.h"
#include <iostream>
#include <vector>
#include <boost/function.hpp>
#include <boost/mem_fn.hpp>
namespace Core
	{
	namespace State
		{
		class MainMenu : public Menu
			{
			public:
				MainMenu(Interface::BaseController& menu_controller);

				~MainMenu();

				void update();

				void render(sf::RenderTarget& target);
			private:
				void onClicked_quit();
				void onClicked_campaign();
				void onClicked_skirmish();
				void onClicked_options();
			};
		}
	}
#endif
