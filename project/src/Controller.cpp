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
		this->exitGame(event);
		this->mouseEventReleased(event);
		this->mouseEventMoved(event);
	}
	this->keyboardEvent();
	this->isPlaying();
}
//_______________________________________________
void Controller::exitGame(const sf::Event& event)
{
	if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		|| event.type == sf::Event::Closed || m_window.isExit())
		m_gameWindow.close();
}
//_________________________________________________________
void Controller::mouseEventReleased(const sf::Event& event)
{
	if (sf::Event::MouseButtonReleased)
	{
		// getting the location of where the mouse was pressed
		auto location = m_gameWindow.mapPixelToCoords(
			{ event.mouseButton.x, event.mouseButton.y });
		m_window.handleClickInWindow(location);
	}
}
//______________________________________________________
void Controller::mouseEventMoved(const sf::Event& event)
{
	if (event.type == sf::Event::MouseMoved)
		m_window.catchMouseEvent(m_gameWindow, event);
}
//______________________________
void Controller::keyboardEvent()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		this->decideActivePlayer();
}
//___________________________________
void Controller::decideActivePlayer()
{
	m_activePlayer++;
	if (m_activePlayer > 3)
		m_activePlayer = 0;
}
//__________________________
void Controller::isPlaying()
{
	if (m_window.isPlaying())
	{
		const auto deltaTime = m_gameClock.restart();
		m_players[m_playersLocation[m_activePlayer]]->move(deltaTime);
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