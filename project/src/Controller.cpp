#include "Controller.hpp"

//______________________
Controller::Controller()
{
	m_gameTexture.loadFromFile("play.png");
	m_gameSprite.setTexture(m_gameTexture);
	m_board.setObjectsFromBoard(m_players);
	this->findMovingPlayersLocation();
}
//__________________________________________
void Controller::findMovingPlayersLocation()
{
	for (int i = 0; i < m_players.size(); i++)
	{
		switch (m_players[i]->getKey())
		{
		case KING:
			m_playersLocation[KING_BOARD_OBJECT] = i;
			break;

		case MAGE:
			m_playersLocation[MAGE_BOARD_OBJECT] = i;
			break;

		case WARRIOR:
			m_playersLocation[WARRIOR_BOARD_OBJECT] = i;
			break;

		case THIEF:
			m_playersLocation[THIEF_BOARD_OBJECT] = i;
			break;
		}
	}
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
		if (event.type == sf::Event::MouseMoved)
			m_window.catchMouseEvent(m_gameWindow, event);
		if (sf::Keyboard::Key::P)
			m_activePlayer = decideActivePlayer(m_count);
			
	}
	if (m_window.isPlaying())
	{
		const auto deltaTime = m_gameClock.restart();
		m_players[m_playersLocation[m_activePlayer]]->move(deltaTime);
	}
}
//___________________________________________________
int Controller::decideActivePlayer(int& countKeyBoard)
{
	countKeyBoard++;
	if ((countKeyBoard - 1) % numOfPlayers == 0)
	{
		return KING_BOARD_OBJECT;
	}
	else if ((countKeyBoard - 1) % numOfPlayers == 1)
	{
		return MAGE_BOARD_OBJECT;
	}
	else if ((countKeyBoard - 1) % numOfPlayers == 2)
	{
		return WARRIOR_BOARD_OBJECT;
	}
	else if ((countKeyBoard - 1) % numOfPlayers == 3)
	{
		return THIEF_BOARD_OBJECT;
	}
	return 1;
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