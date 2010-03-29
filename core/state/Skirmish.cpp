#include "Skirmish.h"
using namespace Core;
using namespace State;

Skirmish::Skirmish(Interface::BaseController& controlA, Interface::BaseController& controlB) :
	Battle("Skirmish", controlA, controlB)
	{
	m_units.push_back( Object::GroupFactory::getGroup("knight", Utility::fPoint(64, 64)) );
	}


Skirmish::~Skirmish()
	{
	for(std::vector<Object::Group*>::iterator unit = m_units.begin(); unit != m_units.end(); ++unit)
		{
		delete *unit;
		}
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


	// Update the units
	for(std::vector<Object::Group*>::iterator unit = m_units.begin(); unit != m_units.end(); ++unit)
		{
		(*unit)->update();
		}
	}


void Skirmish::render(sf::RenderTarget& target)
	{
	for(std::vector<Object::Group*>::iterator unit = m_units.begin(); unit != m_units.end(); ++unit)
		{
		(*unit)->render(target);
		}
	}
