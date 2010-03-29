#include "Game.h"
using namespace Core;

const std::string Game::s_defaultState("MainMenu");

Game::Game() :
	m_currentState(s_defaultState),
	m_window(sf::VideoMode(800, 600, 32), "Test Settings", sf::Style::Close),
	m_playerControlA(m_window),
	m_playerControlB(m_window)
	{
	Utility::ModuleManager::SetModuleSearchPath("module");

	//Relative Positioning
	Interface::ButtonFactory::addRelativePosition("TOP_LEFT", Utility::fPoint(0, 0));
	Interface::ButtonFactory::addRelativePosition("TOP_MIDDLE", Utility::fPoint(400, 0));
	Interface::ButtonFactory::addRelativePosition("TOP_RIGHT", Utility::fPoint(800, 0));
	
	Interface::ButtonFactory::addRelativePosition("MIDDLE_LEFT", Utility::fPoint(0, 300));
	Interface::ButtonFactory::addRelativePosition("CENTER", Utility::fPoint(400, 300));
	Interface::ButtonFactory::addRelativePosition("MIDDLE_RIGHT", Utility::fPoint(800, 300));

	Interface::ButtonFactory::addRelativePosition("BOTTOM_LEFT", Utility::fPoint(0, 600));
	Interface::ButtonFactory::addRelativePosition("BOTTOM_MIDDLE", Utility::fPoint(400, 600));
	Interface::ButtonFactory::addRelativePosition("BOTTOM_RIGHT", Utility::fPoint(800, 600));
	// --

	m_playerControlA.allowAutoClose(true);

	addState(new State::MainMenu(m_playerControlA));
	addState(new State::Quit(m_window));
	addState(new State::Skirmish(m_playerControlA, m_playerControlB));
	setState(s_defaultState);
	}


Game::~Game()
	{
	for(std::map<std::string, State::BaseState*>::iterator state_itr = m_states.begin();
		state_itr != m_states.end();
		++state_itr)
		{
		delete state_itr->second;
		}
	}


sf::RenderWindow& Game::getRenderWindow()
	{
	return m_window;
	}

void Game::run()
	{
	while(m_window.IsOpened())
		{
		if(!stateExists(m_currentState))
			{
			std::cerr << "Error current state: " << 
				m_currentState << " does not exist" << std::endl;
			}
	
		//Observe current state to see if we need to change states
		if(m_states[m_currentState]->getCurrentState() != m_states[m_currentState]->getName())
			{
			m_currentState = m_states[m_currentState]->getCurrentState();
			}
		
#ifndef NDEBUG
		if(!stateExists(m_currentState))
			{
			std::cerr << "Error new (recently changed) state: " << 
				m_currentState << " does not exist" << std::endl;
			}
#endif
		m_states[m_currentState]->update();

		m_window.Clear(sf::Color(30, 30, 30, 0));
		m_states[m_currentState]->render(m_window);
		m_window.Display();
		}


	}


void Game::setState(const std::string& name)
	{
#ifndef NDEBUG
	if(!stateExists(name))
		{
		std::cerr << "Error attempt to change state from " 
			<< m_currentState << " to non-existing state " << name << std::endl;
		}
#endif

	m_currentState = name;
	}


void Game::addState(State::BaseState* state)
	{
#ifndef NDEBUG
	std::cout << "Adding state: " << state->getName() << std::endl;
	if(stateExists(state->getName()))
		{
		std::cerr << "Attempt to reload state: " << state->getName() << std::endl;
		return;
		}
#endif

	m_states[state->getName()] = state;
	}


bool Game::stateExists(const std::string& name)
	{
	return ( m_states.find(name) != m_states.end() );
	}
