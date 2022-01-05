#include "Controller.hpp"

//______________________
Controller::Controller()
	: m_activePlayer(0), m_gameTime(sf::seconds(300))
{
}
//________________________
void Controller::runGame()
{
	while (!m_board.checkEndOfFile())
	{
		m_board.setObjectsFromBoard(m_players, m_statics, m_teleports);
		this->runLevel();
		m_players.clear();
		m_statics.clear();
		m_gameTime += sf::seconds(4);
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
			if (/*checkGameTime(clock)*/ this->chechKingOnThrone())
			{
				clock.restart();
				break;
			}
		}
		this->handleEvents();
	}
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
	isPlaying();
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
		this->decideActivePlayer();
}
//___________________________________
void Controller::decideActivePlayer()
{
	m_activePlayer < 3 ? m_activePlayer++ : m_activePlayer = 0;
}
//__________________________
void Controller::isPlaying()
{
	if (m_window.isPlaying())
	{
		const auto deltaTime = m_moveClock.restart();
		m_players[m_activePlayer]->move(deltaTime);
		checkCollision(*m_players[m_activePlayer]);
		handleDaedObjects();
	}
}
//____________________________________________________
void Controller::checkCollision(MovingObjects &activePlayer)
{
	openTeleport(activePlayer);
	for (int i = 0; i < m_statics.size(); i++)
		if (activePlayer.checkCollision(*m_statics[i]))
			activePlayer.collide(*m_statics[i]);

	for (auto &movalbe : m_players)
		if (activePlayer.checkCollision(*movalbe) && &activePlayer != &(*movalbe))
			activePlayer.setPosition();

	for (auto &teleports : m_teleports)
		if (activePlayer.checkCollision(*teleports) && teleports->isTelOpen())
		{
			activePlayer.collide(*teleports);
			m_teleports[teleports->getNextTelIndex()]->setClose();
			m_teleportIndex = teleports->getNextTelIndex();
		}
}
//________________________________________________________
void Controller::openTeleport(MovingObjects &activePlayer)
{
	if (activePlayer.checkCollision(*m_teleports[m_teleportIndex]))
		return;
	m_teleports[m_teleportIndex]->setOpen();
}
//_________________________________
void Controller::handleDaedObjects()
{
	for (int i = 0; i < m_statics.size(); i++)
		if (typeid(*m_statics[i]) == typeid(MonsterObject) && m_statics[i]->isDead())
			m_board.addStaticObjects(m_statics, m_teleports, m_statics[i]->getPosition(), GATE_KEY);

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