#include "Controller.hpp"

//______________________
Controller::Controller()
	: m_activePlayer(0), m_numOfLevel(0), m_gameTime(levelTimes[0])
{
	m_gameClock.restart();
	m_moveClock.restart();
}
//________________________
void Controller::runGame()
{
	while (!m_data.endOfFile())
	{
		m_data.setDataObjects();
		runLevel();
		m_data.clearObjects();
		m_data.clearBoard();
		m_numOfLevel++;
		m_gameTime = levelTimes[m_numOfLevel];
	}
}
//_________________________
void Controller::runLevel()
{
	while (m_gameWindow.isOpen())
	{
		if (!m_window.isPlaying())
			m_window.drawWindow(m_gameWindow);
		else
		{
			bool key = m_data.thiefHasKey();
			m_window.drawPlay(m_gameWindow, m_gameTime, m_numOfLevel, key, false, m_activePlayer);
			m_data.drawObjects(m_gameWindow, m_window.isPause());
			if (m_data.wonLevel())
				break;
			if (!m_window.isPause())
			{
				handleGameOver(key);
				playTime();
			}
			else
				m_moveClock.restart();
		}
		handleEvents();
	}
}
//_____________________________________________
void Controller::handleGameOver(const bool key)
{
	if (checkGameTime())
	{
		m_window.drawPlay(m_gameWindow, m_gameTime, m_numOfLevel,
						  key, true, m_activePlayer);
		m_data.drawObjects(m_gameWindow, true);
		restartLevel();
	}
}
//____________________________________
bool Controller::checkGameTime() const
{
	return m_gameTime < 0;
}
//_____________________________
void Controller::restartLevel()
{
	m_data.clearObjects();
	m_data.setDataObjects();
	m_gameTime = levelTimes[m_numOfLevel];
	m_activePlayer = 0;
}
//_________________________
void Controller::playTime()
{
	if (m_gameClock.getElapsedTime().asSeconds() > 1)
	{
		--m_gameTime;
		m_gameClock.restart();
	}
}
//_____________________________
void Controller::handleEvents()
{
	auto event = sf::Event();
	while (m_gameWindow.pollEvent(event))
	{
		exitGame(event);
		mouseEventReleased(event);
		mouseEventMoved(event);
	}
	keyboardEvent(event);
	isPlaying(event);
}
//_______________________________________________
void Controller::exitGame(const sf::Event &event)
{
	if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) ||
		event.type == sf::Event::Closed || m_window.isExit())
		m_gameWindow.close();
}
//_________________________________________________________
void Controller::mouseEventReleased(const sf::Event &event)
{
	if (sf::Event::MouseButtonReleased)
	{
		// getting the location of where the mouse was pressed
		auto location = m_gameWindow.mapPixelToCoords(
			{event.mouseButton.x, event.mouseButton.y});
		m_window.handleClickInWindow(location);
	}
}
//______________________________________________________
void Controller::mouseEventMoved(const sf::Event &event)
{
	if (event.type == sf::Event::MouseMoved)
		m_window.catchMouseEvent(m_gameWindow, event);
}
//____________________________________________________
void Controller::keyboardEvent(const sf::Event &event)
{
	if (event.key.code == sf::Keyboard::P)
		decideActivePlayer();
}
//___________________________________
void Controller::decideActivePlayer()
{
	m_activePlayer < numOfPlayers - 1 ? m_activePlayer++ : m_activePlayer = 0;
}
//________________________________________________
void Controller::isPlaying(const sf::Event &event)
{
	if (m_window.isPlaying() && !m_window.isPause())
	{
		const auto deltaTime = m_moveClock.restart();
		m_data.moveData(event, deltaTime, m_activePlayer);
	}
}
