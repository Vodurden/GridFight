#include "Skirmish.h"
using namespace Core;
using namespace State;

Skirmish::Skirmish(Interface::BaseController& controlA, Interface::BaseController& controlB) :
	Battle("Skirmish", controlA, controlB),
	m_grid("skirmish")
	{

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
	}
