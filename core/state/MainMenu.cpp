#include "MainMenu.h"
using namespace Core::State;
using namespace Interface;

MainMenu::MainMenu(Interface::BaseController& menu_controller) :
	Menu(menu_controller, "MainMenu")
	{
	Interface::Button* campaign_button = Interface::ButtonFactory::getButton("main_menu.campaign");
	bindButton(campaign_button, boost::bind(&MainMenu::onClicked_campaign, this));
	addButton(campaign_button);

	Interface::Button* skirmish_button = Interface::ButtonFactory::getButton("main_menu.skirmish");
	bindButton(skirmish_button, boost::bind(&MainMenu::onClicked_skirmish, this));
	addButton(skirmish_button);

	Interface::Button* options_button = Interface::ButtonFactory::getButton("main_menu.options");
	bindButton(options_button, boost::bind(&MainMenu::onClicked_options, this));
	addButton(options_button);

	Interface::Button* quit_button = Interface::ButtonFactory::getButton("main_menu.quit");
	bindButton(quit_button, boost::bind(&MainMenu::onClicked_quit, this));
	addButton(quit_button);
	}

MainMenu::~MainMenu()
	{
	for(std::vector<Button*>::iterator pButtonItr = m_buttons.begin();
		pButtonItr != m_buttons.end();
		++pButtonItr)
		{
		delete *pButtonItr;
		}
	}

void MainMenu::onClicked_quit()
	{
	setCurrentState("quit");
	}

void MainMenu::onClicked_campaign()
	{
	std::cout << "Starting Campaign (UNIMPLEMENTED)" << std::endl;
	}

void MainMenu::onClicked_skirmish()
	{
	setCurrentState("Skirmish");
	}

void MainMenu::onClicked_options()
	{
	std::cout << "Loading Options (UNIMPLEMENTED)" << std::endl;
	}

void MainMenu::update()
	{
	System::Event event;
	while(m_refController.getEvent(event))
		{
		manageEvent(event);
		}
	}

void MainMenu::render(sf::RenderTarget& target)
	{
	for(std::vector<Button*>::iterator pButtonItr = m_buttons.begin();
		pButtonItr != m_buttons.end();
		++pButtonItr)
		{
		(*pButtonItr)->draw(target);
		}
	}
