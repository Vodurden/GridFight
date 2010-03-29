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
