#include "Controller.hpp"

//______________________
Controller::Controller()
{
	m_players.push_back(std::make_unique<KingObject>());
	m_players.push_back(std::make_unique<WarriorObject>());
}
//________________________
void Controller::runGame()
{
	while (m_gameWindow.isOpen())
	{
		m_window.print(m_gameWindow);
		//m_window.draw(m_players[0]);
		this->handleEvents();
	}
}
//_________________________
void Controller::handleEvents()
{

	for (auto event = sf::Event(); m_gameWindow.pollEvent(event);)
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
	if (m_window.isPlaying())
	{
		const auto deltaTime = m_gameClock.restart();
		m_players[0]->move(deltaTime);
	}
}
