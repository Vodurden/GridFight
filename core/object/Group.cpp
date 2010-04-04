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


void Group::setOffset(Utility::fPoint offset)
	{
	for(UnitIter unitPos = m_units.begin();
		unitPos != m_units.end();
		++unitPos)
		{
		unitPos->unit->setOffset(offset);
		}
	update();
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


void Group::advance()
	{
	m_pos.setX(m_pos.getX() + 1);
	update();
	}


void Group::retreat()
	{
	m_pos.setX(m_pos.getX() - 1);
	update();
	}


void Group::addUnit(Utility::iPoint pos, BaseUnit* unit)
	{
	m_units.push_back(UnitPosition(pos, unit));
	m_unitReferences.push_back(unit);
	update();
	}


std::vector<std::pair<Utility::fPoint, Utility::fPoint> > Group::getUnitBorderPoints(
	BaseUnit& unit, 
	const Utility::fPoint gridTileSize
	)
	{
	std::vector<std::pair<Utility::fPoint, Utility::fPoint> > points;

	// Top Line
	BaseUnit* adjacentUnit = getRelativeUnit(unit, Utility::iPoint(0, -1));
	if( adjacentUnit == NULL )
		{
		points.push_back(std::pair<Utility::fPoint, Utility::fPoint>(
			Utility::fPoint(0, 0),
			Utility::fPoint(gridTileSize.getX(), 0)	
			));
		}
	
	// Right Line
	adjacentUnit = getRelativeUnit(unit, Utility::iPoint(1, 0));
	if( adjacentUnit == NULL )
		{
		points.push_back(std::pair<Utility::fPoint, Utility::fPoint>(
			Utility::fPoint(gridTileSize.getX(), 0),
			Utility::fPoint(gridTileSize.getX(), gridTileSize.getY())
			));
		}
	
	adjacentUnit = getRelativeUnit(unit, Utility::iPoint(0, 1));
	if( adjacentUnit == NULL )
		{
		points.push_back(std::pair<Utility::fPoint, Utility::fPoint>(
			Utility::fPoint(gridTileSize.getX(), gridTileSize.getY()),
			Utility::fPoint(0.0f, gridTileSize.getY())
			));
		}
	
	//Construct the left border if there is no unit to the left
	adjacentUnit = getRelativeUnit(unit, Utility::iPoint(-1, 0));
	if( adjacentUnit == NULL )
		{
		points.push_back(std::pair<Utility::fPoint, Utility::fPoint>(
			Utility::fPoint(0, gridTileSize.getY()),
			Utility::fPoint(0, 0)
			));
		}
	
	return points;
	}


bool Group::isBeyondBoundry(int boundryPosition)
	{
	for(UnitIter unit_kv = m_units.begin();
		unit_kv != m_units.end();
		++unit_kv)
		{
		if( (m_pos + unit_kv->pos).getX() >= boundryPosition )
			{
			return true;
			}
		}
	return false;
	}


//Warning: this will break if "unit" does not exist
// within this group
BaseUnit* Group::getRelativeUnit(BaseUnit& unit, Utility::iPoint pos)
	{
	//Find this units position 
	Utility::iPoint unitPos;
	for(UnitIter unit_kv = m_units.begin(); 
		unit_kv != m_units.end();
		++unit_kv)
		{
		//Check if this is the exact same unit
		if(&unit == unit_kv->unit)
			{
			unitPos = unit_kv->pos;
			break;
			}
		}
	
	//Find the unit adjacent to that point
	for(UnitIter unit_kv = m_units.begin();
		unit_kv != m_units.end();
		++unit_kv)
		{
		if((unitPos + pos) == unit_kv->pos)
			{
			return (unit_kv->unit);
			}
		}
	
	return NULL;
	}


Group::iterator Group::begin()
	{
	return m_unitReferences.begin();
	}


Group::iterator Group::end()
	{
	return m_unitReferences.end();
	}
