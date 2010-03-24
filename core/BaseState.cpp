#include "BaseState.h"
using namespace Core::State;

BaseState::BaseState(const std::string& name) :
	m_name(name),
	m_currentState(name)
	{

	}

BaseState::~BaseState()
	{

	}

std::string BaseState::getName() const
	{
	return m_name;
	}

std::string BaseState::getCurrentState() const
	{
	return m_currentState;
	}

void BaseState::setCurrentState(const std::string& state)
	{
	m_currentState = state;
	}

void BaseState::render(sf::RenderTarget& target)
	{

	}
