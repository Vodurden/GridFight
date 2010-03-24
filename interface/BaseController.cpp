#include "BaseController.h"
using namespace Interface;

BaseController::~BaseController()
	{

	}


void BaseController::addEvent(System::Event event)
	{
	m_events.push(event);
	}

System::Event& BaseController::getCurrentEvent()
	{
	if(eventQueued())
		{
		return m_events.front();
		}
	
	m_errorEvent.type = System::Event::Error;
	return m_errorEvent;
	}

void BaseController::moveToNextEvent()
	{
	m_events.pop();
	}

bool BaseController::eventQueued()
	{
	return (m_events.size() != 0);
	}
