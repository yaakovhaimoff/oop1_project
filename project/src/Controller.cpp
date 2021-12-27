#include "Controller.hpp"

//________________________
Controller::Controller()
{}

//__________________________
void Controller::runGame()
{
	while (m_gameWindow.isOpen())
	{
		m_window.print(m_gameWindow);
		this->handleEvents();
	}
}
//_________________________
void Controller::handleEvents()
{
	sf::Event event;
	while (m_gameWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::Escape))
			m_gameWindow.close();
		if (sf::Event::MouseButtonReleased)
		{
			// getting the location of where the mouse was pressed
			auto location = m_gameWindow.mapPixelToCoords(
				{ event.mouseButton.x, event.mouseButton.y });
			m_window.handleClickInWindow(location);
			if (m_window.isExit())
			{
				m_gameWindow.close();
				break;
			}
		}
	}
}
