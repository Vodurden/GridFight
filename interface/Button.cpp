#include "Button.h"
using namespace Interface;

Button::Button(Utility::fPoint pos) :
	m_state(STATE_NONE),
	m_pos(pos)
	{
	
	}

Button::~Button()
	{

	}

void Button::setPosition(Utility::fPoint pos)
	{
	m_pos = pos;
	}

Utility::fPoint Button::getPosition()
	{
	return m_pos;
	}


Button::State Button::getState()
	{
	return m_state;
	}

void Button::setState(const State& state)
	{
	m_state = state;
	}
