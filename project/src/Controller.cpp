#include "Controller.hpp"

//______________________
Controller::Controller()
	: m_activePlayer(0), m_numOfLevel(0), m_gameTime(sf::seconds(levelTimes[0]))
{
}
//________________________
void Controller::runGame()
{
	while (!m_board.checkEndOfFile())
	{
		m_board.setObjectsFromBoard(m_players, m_statics, m_teleports, m_numOfLevel);
		runLevel();
		clearObjects();
		m_board.clearBoard();
		m_numOfLevel++;
		m_gameTime = sf::seconds(levelTimes[m_numOfLevel]);
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
			static sf::Clock clock;
			m_window.drawPlay(m_gameWindow, clock, m_gameTime, m_players, m_statics, m_teleports);
			if (chechKingOnThrone())
			{
				clock.restart();
				break;
			}
			if (checkGameTime(clock))
			{
				restartLevel();
				clock.restart();
			}
		}
		handleEvents();
	}
}
//_____________________________
void Controller::restartLevel()
{
	clearObjects();
	m_board.sendBoardKeysToObjects(m_players, m_statics, m_teleports, m_numOfLevel);
	m_gameTime = sf::seconds(levelTimes[m_numOfLevel]);
	m_activePlayer = 0;
}
//_____________________________
void Controller::clearObjects()
{
	m_players.clear();
	m_statics.clear();
	m_teleports.clear();
}
//__________________________________________________________
bool Controller::checkGameTime(const sf::Clock &clock) const
{
	return clock.getElapsedTime() > m_gameTime;
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
//______________________________________________
void Controller::isPlaying(const sf::Event &event)
{
	if (m_window.isPlaying())
	{
		moveObjects(event);
		checkCollision(*m_players[m_activePlayer]);
		handleDaedObjects();
	}
}
//___________________________________________________
void Controller::moveObjects(const sf::Event &event)
{
	const auto deltaTime = m_moveClock.restart();
	m_players[m_activePlayer]->move(deltaTime, event);
	for (int i = numOfPlayers; i < m_players.size(); i++)
		m_players[i]->move(deltaTime, event);
}
//____________________________________________________
void Controller::checkCollision(MovingObjects &activePlayer)
{
	openTeleport(activePlayer);
	for (auto &unmovable : m_statics)
		if (activePlayer.checkCollision(*unmovable))
			activePlayer.collide(*unmovable);

	for (auto &movalbe : m_players)
		if (activePlayer.checkCollision(*movalbe) && &activePlayer != &(*movalbe))
			activePlayer.setPosition();

	for (auto &teleports : m_teleports)
		if (activePlayer.checkCollision(*teleports) && teleports->isTelOpen())
		{
			activePlayer.collide(*teleports);
			m_teleports[teleports->getNextTelIndex()]->setLock(false);
			m_teleportIndex = teleports->getNextTelIndex();
		}

	for (int i = numOfPlayers; i < m_players.size(); i++)
		for (int j = 0; j < m_statics.size(); j++)
			if (m_players[i]->checkCollision(*m_statics[j]))
				dynamic_cast<DwarfObject *>(m_players[i].get())->setDirection(rand() % 4);
	// m_players[i]->collide(*m_statics[j]);
}
//________________________________________________________
void Controller::openTeleport(MovingObjects &activePlayer)
{
	if (activePlayer.checkCollision(*m_teleports[m_teleportIndex]))
		return;
	m_teleports[m_teleportIndex]->setLock(true);
}
//_________________________________
void Controller::handleDaedObjects()
{
	for (int i = 0; i < m_statics.size(); i++)
	{
		if (typeid(*m_statics[i]) == typeid(MonsterObject) && m_statics[i]->isDead())
			m_board.addObjects(m_players, m_statics, m_teleports, m_statics[i]->getPosition(), GATE_KEY);
		if (typeid(*m_statics[i]) == typeid(GiftObject) && m_statics[i]->isDead())
			m_gameTime += sf::seconds(getTimeForGift());
	}

	std::erase_if(m_statics, [](auto &staticObject)
				  { return staticObject->isDead(); });
}
//_______________________________________
bool Controller::chechKingOnThrone() const
{
	for (int i = 0; i < m_statics.size(); i++)
		if (typeid(*m_statics[i]) == typeid(CrownObject))
			return false;
	return true;
}
//______________________________
int Controller::getTimeForGift()
{
	return rand() % 60 + (-60);
}
