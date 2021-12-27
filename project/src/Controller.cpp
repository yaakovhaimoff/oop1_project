#include "Controller.hpp"

//______________________
Controller::Controller()
{
	m_gameTexture.loadFromFile("play.png");
	m_gameSprite.setTexture(m_gameTexture);
	m_players.push_back(std::make_unique<KingObject>());
	m_players.push_back(std::make_unique<WarriorObject>());
}
//________________________
void Controller::runGame()
{
	while (m_gameWindow.isOpen())
	{
		if (!m_window.isPlaying())
			m_window.drawWindow(m_gameWindow);
		else
			this->drawGameWindow();
		this->handleEvents();
	}
}
//_____________________________
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
//_______________________________
void Controller::drawGameWindow()
{
	m_gameWindow.clear();
	m_gameWindow.draw(m_gameSprite);
	for (int i = 0; i < m_players.size(); i++)
		m_players[i]->drawShape(m_gameWindow);
	m_gameWindow.display();
}