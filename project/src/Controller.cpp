#include "Controller.hpp"

//______________________
Controller::Controller()
	: m_activePlayer(0)
{
	m_gameTexture.loadFromFile("play.png");
	m_gameSprite.setTexture(m_gameTexture);
	m_board.setObjectsFromBoard(m_players, m_statics);
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
		sf::RectangleShape save;
		const auto deltaTime = m_gameClock.restart();
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
	for (int i = 0; i < m_players.size(); i++)
		if (m_players[m_activePlayer]->checkCollision(*m_players[i]) && i!= m_activePlayer)
		{
			m_players[m_activePlayer]->collide(*m_players[i]);
		}
}
//_______________________________
void Controller::drawGameWindow()
{
	m_gameWindow.clear();
	m_gameWindow.draw(m_gameSprite);
	this->drawObjects();
	m_gameWindow.display();
}
//____________________________
void Controller::drawObjects()
{
	for (int i = 0; i < m_statics.size(); i++)
		m_statics[i]->drawShape(m_gameWindow);
	for (int i = 0; i < m_players.size(); i++)
		m_players[i]->drawShape(m_gameWindow);
}
