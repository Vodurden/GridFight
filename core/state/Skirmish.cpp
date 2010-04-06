#include "Skirmish.h"
using namespace Core;
using namespace State;

Skirmish::Skirmish(Interface::BaseController& controlA, Interface::BaseController& controlB) :
	Battle("Skirmish", controlA, controlB),
	m_grid("skirmish")
	{
	m_grid.addGroup(Object::GroupFactory::getGroup("knight", m_grid.getTileSize()));
	}


Skirmish::~Skirmish()
	{

	}


void Skirmish::update()
	{
	/**
	 * Poll ControllerA and ControllerB
	 * on the same computer this is going
	 * to be the same event poll, but in some
	 * cases it may be an AI or another computer
	 * generating the events
	 */
	
	// Player 1
	System::Event event;
	while(getControllerA().getEvent(event))
		{
		if(event.type == System::Event::MouseButtonReleased)
			{
			if(event.MouseButton.Button == System::Mouse::Left)
				{
				m_grid.addGroup(Object::GroupFactory::getGroup("knight", m_grid.getTileSize()));
				}
			else if(event.MouseButton.Button == System::Mouse::Right)
				{
				m_grid.addGroup(Object::GroupFactory::getGroup("ninja", m_grid.getTileSize()));
				}
			}
		}
	
	// Player 2
	while(getControllerB().getEvent(event))
		{

		}


	m_grid.update();
	}


void Skirmish::render(sf::RenderTarget& target)
	{
	m_grid.render(target);

	Interface::FormattedTextArea test(Utility::fPoint(150.0f, 150.0f), Utility::fPoint(400.0f, 350.0f));
	test << Interface::Style::Bold << Interface::Color::Blue << Interface::Position::Center << "--TITLE--\n";
	test << Interface::Style::Regular << Interface::Color::Green << Interface::Position::Left << "[" <<
		Interface::Color::Blue << "[";
	test << Interface::Style::Bold << Interface::Color::Blue << Interface::Position::Right << "]\n";
	test << Interface::Position::Left << Interface::Color::Red << Interface::Style::Italic << Interface::Position::Center <<"I am italic centered red and also rather long\n";
	test << Interface::Position::Left << Interface::Color::Red << "Half Red" << Interface::Color::Blue << "Half Blue\n";
	test << Interface::Position::Left << "[" << Interface::Position::Center << Interface::Color::Cyan<< "----" << Interface::Position::Right << Interface::Color::Green << "]\n";
	test << Interface::Style::Regular << Interface::Position::Center << "I am some normal text\n";
	test.render(target);
	}
