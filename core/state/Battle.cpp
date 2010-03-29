#include "Battle.h"
using namespace Core;
using namespace State;

Battle::Battle(const std::string& name, Interface::BaseController& controlA, Interface::BaseController& controlB) :
	BaseState(name),
	m_controllerA(controlA),
	m_controllerB(controlB)
	{

	}


Battle::~Battle() {}


Interface::BaseController& Battle::getControllerA()
	{
	return m_controllerA;
	}


Interface::BaseController& Battle::getControllerB()
	{
	return m_controllerB;
	}
