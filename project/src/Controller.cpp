#include "Controller.hpp"

//______________________
Controller::Controller()
	: m_activePlayer(0), m_numOfLevel(0), m_teleportIndex(0),
	  m_gameTime(sf::seconds(levelTimes[0])), m_changeDwarfDir(false) {}
//________________________
void Controller::runGame()
{
	while (!m_board.checkEndOfFile())
	{
		m_board.setObjectsFromBoard(m_players, m_statics, m_teleports);
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
			bool key = dynamic_cast<ThiefObject *>(m_players[THIEF_BOARD_OBJECT].get())->doesThiefhasKey();
			m_window.drawPlay(m_gameWindow, clock, m_gameTime, m_numOfLevel,
							  key, m_players, m_statics, m_teleports, false, m_activePlayer);
			if (wonLevel())
			{
				clock.restart();
				break;
			}
			handleGameOver(clock, key);
		}
		handleEvents();
	}
}

//_______________________________________________________________
void Controller::handleGameOver(sf::Clock &clock, const bool key)
{
	if (checkGameTime(clock))
	{
		m_window.drawPlay(m_gameWindow, clock, m_gameTime, m_numOfLevel,
						  key, m_players, m_statics, m_teleports, true, m_activePlayer);
		restartLevel();
		clock.restart();
	}
}
//_____________________________
void Controller::restartLevel()
{
	clearObjects();
	m_board.sendBoardKeysToObjects(m_players, m_statics, m_teleports);
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
//_______________________________________________
void Controller::isPlaying(const sf::Event &event)
{
	if (m_window.isPlaying())
	{
		moveObjects(event);
		checkPlayerCollision(*m_players[m_activePlayer]);
		checkDwarfCollision(event);
		handleDaedObjects();
	}
}
//__________________________________________________
void Controller::moveObjects(const sf::Event &event)
{
	const auto deltaTime = m_moveClock.restart();
	m_players[m_activePlayer]->move(deltaTime, event);
	static sf::Clock clock;

	for (int i = numOfPlayers; i < m_players.size(); i++)
	{
		m_players[i]->move(deltaTime, event);
		if (clock.getElapsedTime().asSeconds() > 1.0f)
		{
			dynamic_cast<DwarfObject *>(m_players[i].get())->setDirection();
			m_changeDwarfDir = true;
		}
	}
	if (m_changeDwarfDir)
	{
		m_changeDwarfDir = false;
		clock.restart();
	}
}
//____________________________________________________
void Controller::checkPlayerCollision(MovingObjects &activePlayer)
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
}
//___________________________________________________________
void Controller::checkDwarfCollision(const sf::Event &event)
{
	for (int i = numOfPlayers; i < m_players.size(); i++)
		for (int j = 0; j < m_statics.size(); j++)
			if (m_players[i]->checkCollision(*m_statics[j]))
				m_players[i]->collide(*m_statics[j]);
}
//________________________________________________________
void Controller::openTeleport(MovingObjects &activePlayer)
{
	// while the player is on the teleport, the teleport stays closed,
	//  and the collision is not checked
	if (activePlayer.checkCollision(*m_teleports[m_teleportIndex]))
		return;
	m_teleports[m_teleportIndex]->setLock(true);
}
//_________________________________
void Controller::handleDaedObjects()
{
	for (auto &unmovable : m_statics)
	{
		if (typeid(*unmovable) == typeid(MonsterObject) && unmovable->isDead())
			m_board.addObjects(m_players, m_statics, m_teleports, unmovable->getPosition(), GATE_KEY);
		else if (typeid(*unmovable) == typeid(TimeGiftObject) && unmovable->isDead())
			m_gameTime += sf::seconds(getTimeForGift());
		else if (typeid(*unmovable) == typeid(RemoveDwarfsObject) && unmovable->isDead())
			removeDwarfs();
	}

	std::erase_if(m_statics, [](auto &staticObject)
				  { return staticObject->isDead(); });
}
//_____________________________
void Controller::removeDwarfs()
{
	int size = m_players.size() - numOfPlayers;
	for (int i = numOfPlayers; size < m_players.size();)
		m_players.erase(m_players.begin() + i);
}
//________________________________
bool Controller::wonLevel() const
{
	for (auto &unmovable : m_statics)
		if (typeid(*unmovable) == typeid(CrownObject))
			return false;
	return true;
}
//______________________________
int Controller::getTimeForGift()
{
	return (rand() % 30 + (-30));
}
