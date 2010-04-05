#include "BaseRenderArea.h"

using namespace Interface;

BaseRenderArea::BaseRenderArea(
	Utility::fPoint pos,
	Utility::fPoint size
	) :
	m_pos(pos),
	m_size(size)
	{

	}


// Required even though the destructor is pure-virtual
// 	Will not compile without
BaseRenderArea::~BaseRenderArea()
	{

	}


Utility::fPoint BaseRenderArea::getPosition() const
	{
	return m_pos;
	}


Utility::fPoint BaseRenderArea::getSize() const
	{
	return m_size;
	}


void BaseRenderArea::setPosition(const Utility::fPoint& position)
	{
	m_pos = position;
	}


void BaseRenderArea::setSize(const Utility::fPoint& size)
	{
	m_size = size;
	}
