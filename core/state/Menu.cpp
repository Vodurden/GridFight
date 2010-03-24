#include "Menu.h"
using namespace Core;
using namespace State;

Menu::Menu(Interface::BaseController& controller, const std::string& name) :
	BaseState(name),
	m_refController(controller),
	m_mouseClicked(false)
	{

	}

Menu::~Menu()
	{

	}

void Menu::manageEvent(System::Event& event)
	{
	if(event.type == System::Event::MouseButtonPressed)
		{
		for(std::vector<Interface::Button*>::iterator pButtonItr = m_buttons.begin();
			pButtonItr != m_buttons.end();
			++pButtonItr)
			{
			if((*pButtonItr)->mouseInsideButton(
				Utility::fPoint(event.MouseButton.X, event.MouseButton.Y)))
				{
				(*pButtonItr)->setState(Interface::Button::STATE_MOUSE_LBUTTON_DOWN);
				m_mouseClicked = true;
				}
			}
		}
	else if(event.type == System::Event::MouseButtonReleased)
		{
		for(std::vector<Interface::Button*>::iterator pButtonItr = m_buttons.begin();
			pButtonItr != m_buttons.end();
			++pButtonItr)
			{
			(*pButtonItr)->setState(Interface::Button::STATE_NONE);
			m_mouseClicked = false;
			if((*pButtonItr)->mouseInsideButton(
				Utility::fPoint(event.MouseButton.X, event.MouseButton.Y)))
				{
				runButton(*pButtonItr);
				}
			}
		}
	else if(event.type == System::Event::MouseMoved)
		{
		for(std::vector<Interface::Button*>::iterator pButtonItr = m_buttons.begin();
			pButtonItr != m_buttons.end();
			++pButtonItr)
			{
			if(m_mouseClicked)
				{
				continue;
				}
			else if((*pButtonItr)->mouseInsideButton(
				Utility::fPoint(event.MouseMove.X, event.MouseMove.Y)))
				{
				(*pButtonItr)->setState(Interface::Button::STATE_MOUSE_HOVER);
				}
			else
				{
				(*pButtonItr)->setState(Interface::Button::STATE_NONE);
				}
			}
		}
	}

void Menu::bindButton(Interface::Button* button, ClickFn func)
	{
	m_buttonClickHandlers[button] = func;
	}

void Menu::addButton(Interface::Button* button)
	{
	m_buttons.push_back(button);
	}

void Menu::runButton(Interface::Button* button)
	{
	m_buttonClickHandlers[button](this);
	}
