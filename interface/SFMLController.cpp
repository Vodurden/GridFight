#include "SFMLController.h"
using namespace Interface;

SFMLController::SFMLController(sf::Window& window) :
	m_refWindow(window),
	m_allowAutoClose(false)
	{

	}


SFMLController::~SFMLController()
	{

	}


void SFMLController::allowAutoClose(const bool close)
	{
	m_allowAutoClose = close;
	}


Utility::iPoint SFMLController::getMousePosition() const
	{
	const sf::Input& sfml_input = m_refWindow.GetInput();
	return Utility::iPoint(sfml_input.GetMouseX(), sfml_input.GetMouseY());
	}


bool SFMLController::isKeyDown(System::Key Key) const
	{
	sf::Key::Code key = static_cast<sf::Key::Code>(static_cast<int>(Key));
	return m_refWindow.GetInput().IsKeyDown(key);
	}


bool SFMLController::isMouseButtonDown(System::Mouse::Button Button) const
	{
	sf::Mouse::Button mouse_button = static_cast<sf::Mouse::Button>(static_cast<int>(Button));
	return m_refWindow.GetInput().IsMouseButtonDown(mouse_button);
	}


bool SFMLController::getEvent(System::Event& out_event)
	{
	//Update the Event Queue
	sf::Event sfmlEvent;
	while(m_refWindow.GetEvent(sfmlEvent))
		{
		addEvent(SFMLEventToSystemEvent(sfmlEvent));

		if(m_allowAutoClose)
			{
			if(sfmlEvent.Type == sf::Event::Closed)
				{
				m_refWindow.Close();
				}
			}
		}

	if(eventQueued())
		{
		out_event = getCurrentEvent();
		moveToNextEvent();
		return true;
		}
	return false;
	}


System::Event SFMLController::SFMLEventToSystemEvent(sf::Event& event)
	{
	System::Event sys_event;
	switch(event.Type)
		{
		case sf::Event::Closed:
			sys_event.type = System::Event::Closed;
			break;
		case sf::Event::Resized:
			sys_event.type = System::Event::Resized;
			break;
		case sf::Event::LostFocus:
			sys_event.type = System::Event::LostFocus;
			break;
		case sf::Event::GainedFocus:
			sys_event.type = System::Event::GainedFocus;
			break;
		case sf::Event::TextEntered:
			sys_event.type = System::Event::Ignore;
			break;
		case sf::Event::KeyPressed:
			sys_event.type = System::Event::KeyPressed;
			break;
		case sf::Event::KeyReleased:
			sys_event.type = System::Event::KeyReleased;
			break;
		case sf::Event::MouseWheelMoved:
			sys_event.type = System::Event::MouseWheelMoved;
			break;
		case sf::Event::MouseButtonPressed:
			sys_event.type = System::Event::MouseButtonPressed;
			break;
		case sf::Event::MouseButtonReleased:
			sys_event.type = System::Event::MouseButtonReleased;
			break;
		case sf::Event::MouseMoved:
			sys_event.type = System::Event::MouseMoved;
			break;
		case sf::Event::MouseEntered:
			sys_event.type = System::Event::MouseEntered;
			break;
		case sf::Event::MouseLeft:
			sys_event.type = System::Event::MouseLeft;
			break;
		case sf::Event::JoyButtonPressed:
			sys_event.type = System::Event::Ignore;
			break;
		case sf::Event::JoyButtonReleased:
			sys_event.type = System::Event::Ignore;
			break;
		case sf::Event::JoyMoved:
			sys_event.type = System::Event::Ignore;
			break;
		default:
			sys_event.type = System::Event::Error;
			break;
		}
	
	//Copy Key Event Data
	if(sys_event.type == System::Event::KeyPressed ||
		sys_event.type == System::Event::KeyReleased)
		{
		sys_event.Key.Code = static_cast<System::Key>(static_cast<int>(event.Key.Code));
		sys_event.Key.Alt = event.Key.Alt;
		sys_event.Key.Control = event.Key.Control;
		sys_event.Key.Shift = event.Key.Shift;
		}
	
	//Copy Mouse Wheel Data
	if(sys_event.type == System::Event::MouseWheelMoved)
		{
		sys_event.MouseWheel.Delta = event.MouseWheel.Delta;
		}
	
	//Copy MouseButtonEvent Data
	if(sys_event.type == System::Event::MouseButtonPressed ||
		sys_event.type == System::Event::MouseButtonReleased)
		{
		sys_event.MouseButton.Button = static_cast<System::Mouse::Button>(static_cast<int>(event.MouseButton.Button));
		sys_event.MouseButton.X = event.MouseButton.X;
		sys_event.MouseButton.Y = event.MouseButton.Y;
		}
	
	//Copy MouseMove Event Data
	if(sys_event.type == System::Event::MouseMoved ||
		sys_event.type == System::Event::MouseEntered ||
		sys_event.type == System::Event::MouseLeft)
		{
		sys_event.MouseMove.X = event.MouseMove.X;
		sys_event.MouseMove.Y = event.MouseMove.Y;
		}
	
	return sys_event;
	}
