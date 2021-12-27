#include "Controller.hpp"

//________________________
Controller::Controller()
{}

//__________________________
void Controller::runGame()
{
	while (m_boardWindow.isOpen())
	{
		m_window.print(m_boardWindow);
		this->handleEvents();
	}
}
//_________________________
void Controller::handleEvents()
{
	sf::Event event;
	while (m_boardWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::Escape))
			m_boardWindow.close();
		if (sf::Event::MouseButtonReleased)
		{
			// getting the location of where the mouse was pressed
			auto location = m_boardWindow.mapPixelToCoords(
				{ event.mouseButton.x, event.mouseButton.y });
			m_window.handleClickInWindow(location);
			if (m_window.isExit())
			{
				m_boardWindow.close();
				break;
			}
		}
	}
}
