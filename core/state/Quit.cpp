#include "Quit.h"
using namespace Core::State;

Quit::Quit(sf::RenderWindow& window) :
	BaseState("quit"),
	m_window(window)
	{

	}

void Quit::update()
	{
	m_window.Close();
	}
