#include "Battle.h"
using namespace Core;
using namespace State;

Battle::Battle(
	const std::string& name,
	BaseController& controlA, 
	BaseController& controlB) :
	BaseState(name),
	m_controllerA(controlA),
	m_controllerB(controlB)
	{

	}
