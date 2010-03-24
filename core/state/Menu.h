#ifndef GRIDFIGHT_CORE_MENU_H
#define GRIDFIGHT_CORE_MENU_H
#include "../BaseState.h"
#include "../../interface/BaseController.h"
#include "../../interface/Button.h"
#include "../../interface/ButtonFactory.h"
#include "../../system/Event.h"
#include <string>
#include <boost/function.hpp>
#include <boost/bind.hpp>
namespace Core
	{
	namespace State
		{
		class Menu : public BaseState
			{
			public:
				typedef boost::function<void (Menu*)> ClickFn;
		
				Menu(Interface::BaseController& controller, const std::string& name);
	
				virtual ~Menu() = 0;
	
				void manageEvent(System::Event& event);

				virtual void update() = 0;

				virtual void render(sf::RenderTarget& target) = 0;
			protected:
				void bindButton(Interface::Button* button, ClickFn func);

				void addButton(Interface::Button* button);

				void runButton(Interface::Button* button);

				Interface::BaseController& m_refController;

				bool m_mouseClicked;

				std::vector<Interface::Button*> m_buttons;

				std::map<Interface::Button*, ClickFn> m_buttonClickHandlers;
			};
		}
	}
#endif
