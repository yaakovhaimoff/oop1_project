#include "Controller.hpp"

//______________________
Controller::Controller()
	: m_activePlayer(0), m_numOfLevel(0),
	  m_gameTime(levelTimes[0]), m_data(*this)
{
	m_data.setDataToLevelStart(m_numOfLevel);
	m_gameTime = m_data.getLevelTime(m_numOfLevel);
	m_moveClock.restart();
	m_gameClock.restart();
}
//_________________________
void Controller::runGame()
{
	while (m_gameWindow.isOpen())
	{
		if (!m_window.isPlaying())
			m_window.drawWindow(m_gameWindow);
		else
		{
			if (isLevelSelected)
			{
				levelSelected();
			}
			drawGame();
			if (m_data.wonLevel())
			{
				setNextLevel();
				if(m_numOfLevel >= LEVELS)
				break;
			}
			if (!m_window.isPause())
			{
				handleGameOver();
				playTime();
			}
			else
				m_moveClock.restart();
		}
		handleEvents();
	}
}
//______________________________
void Controller::levelSelected()
{
	m_numOfLevel = m_window.getLevelSelected();
	m_gameTime = m_data.getLevelTime(m_numOfLevel);
	m_data.clearObjects();
	m_data.setDataToLevelStart(m_numOfLevel);
	isLevelSelected = false;
}
//_____________________________
void Controller::setNextLevel()
{
	m_gameClock.restart();
	m_data.clearObjects();
	m_numOfLevel++;
	m_gameTime = m_data.getLevelTime(m_numOfLevel);
	m_data.setDataToLevelStart(m_numOfLevel);
}
//_______________________________
void Controller::handleGameOver()
{
	if (checkGameTime())
	{
		drawGame();
		m_window.gameOverLevelMessage(m_gameWindow);
		restartLevel();
	}
}
//____________________________________
bool Controller::checkGameTime() const
{
	return m_gameTime < 1;
}
//_____________________________
void Controller::restartLevel()
{
	m_data.clearObjects();
	m_data.setDataToLevelRestart(m_numOfLevel);
	m_gameTime = levelTimes[m_numOfLevel];
	m_activePlayer = 0;
	m_gameClock.restart();
	m_moveClock.restart();
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
//_________________________
void Controller::drawGame()
{
	m_gameWindow.clear();
	m_window.drawPlayWindow(m_gameWindow, m_gameTime, m_numOfLevel, m_data.thiefHasKey(), m_activePlayer);
	m_data.drawObjects(m_gameWindow, m_window.isPause(), checkGameTime());
	m_window.drawPauseMessage(m_gameWindow);
	m_gameWindow.display();
	Resources::instance().stopLoop(menuSound);
	m_gameWindow.setFramerateLimit(12);
}
//______________________________________
void Controller::setTime(const int time)
{
	m_gameTime += time;
}
