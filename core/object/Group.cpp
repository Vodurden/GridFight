#include "Group.h"
using namespace Core;
using namespace Object;

Group::Group(Utility::iPoint pos) :
	m_pos(pos)
	{

	}


Group::~Group()
	{
	for(UnitIter unitPos = m_units.begin();
		unitPos != m_units.end();
		++unitPos)
		{
		delete (unitPos->unit);
		}
	}


bool Group::isColliding(Group& other)
	{
	for(UnitIter myUnit = m_units.begin();
		myUnit != m_units.end();
		++myUnit)
		{
		for(UnitIter otherUnit = other.m_units.begin();
			otherUnit != other.m_units.end();
			++otherUnit)
			{
			if(myUnit->unit->isColliding(*(otherUnit->unit)))
				{
				return true;
				}
			}
		}
	return false;
	}


Utility::iPoint Group::getPosition() const
	{
	return m_pos;
	}


void Group::update()
	{
	for(UnitIter unitPos = m_units.begin();
		unitPos != m_units.end();
		++unitPos)
		{
		unitPos->unit->setPosition(m_pos + unitPos->pos);
		unitPos->unit->update();
		}
	}


void Group::render(sf::RenderTarget& target)
	{
	for(UnitIter unitPos = m_units.begin();
		unitPos != m_units.end();
		++unitPos)
		{
		unitPos->unit->render(target);
		}
	}


void Group::addUnit(Utility::iPoint pos, BaseUnit* unit)
	{
	m_units.push_back(UnitPosition(pos, unit));
	}
