#include "Position.h"
using namespace Interface;

const Position Position::Left(Interface::Position_Left);
const Position Position::Center(Interface::Position_Center);
const Position Position::Right(Interface::Position_Right);

Position::Position(POSITION_TYPE type) :
	m_type(type)
	{

	}


Position::Position(const Position& rhs) :
	m_type(rhs.m_type)
	{

	}


POSITION_TYPE Position::getType() const
	{
	return m_type;
	}


void Position::setType(POSITION_TYPE type)
	{
	m_type = type;
	}
