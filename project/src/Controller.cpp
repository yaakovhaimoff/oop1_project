#include "Controller.hpp"

//______________________
Controller::Controller()
	: m_activePlayer(0), m_gameTime(sf::seconds(60))
{}
//________________________
void Controller::runGame()
{
	while (!m_board.checkEndOfFile())
	{
		m_board.setObjectsFromBoard(m_players, m_statics);
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
			m_window.drawPlay(m_gameWindow, clock, m_gameTime, m_players, m_statics);
			if (checkGameTime(clock))
			{
				clock.restart();
				break;
			}
		}
		this->handleEvents();
	}
}
//__________________________________________________________
bool Controller::checkGameTime(const sf::Clock& clock)const
{
	return clock.getElapsedTime() > m_gameTime;
}
//_____________________________
void Controller::handleEvents()
{
	auto event = sf::Event();
	while (m_gameWindow.pollEvent(event))
	{
		this->exitGame(event);
		this->mouseEventReleased(event);
		this->mouseEventMoved(event);
	}
	this->keyboardEvent(event);
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
//____________________________________________________
void Controller::keyboardEvent(const sf::Event& event)
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
		this->checkCollision();
	}
}
//_______________________________
void Controller::checkCollision()
{
	for (int i = 0; i < m_statics.size(); i++)
		if (m_players[m_activePlayer]->checkCollision(*m_statics[i]))
		{
			m_players[m_activePlayer]->collide(*m_statics[i]);
		}
}
