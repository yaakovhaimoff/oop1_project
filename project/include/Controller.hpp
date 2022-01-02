#pragma once 

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>

#include "Resources.hpp"
#include "macros.hpp"
#include "Window.hpp"
#include "movingObjects.hpp"
#include "staticObjects.hpp"
#include "board.hpp"

class Controller 
{
public:
	Controller();
	void runGame();

private:
	void runLevel();
	void handleEvents();
	void exitGame(const sf::Event&);
	void mouseEventReleased(const sf::Event&);
	void keyboardEvent(const sf::Event&);
	void decideActivePlayer();
	void mouseEventMoved(const sf::Event&);
	void isPlaying();
	void checkCollision(Players&);
	void eraseDeadObjects();
	bool checkGameTime(const sf::Clock&)const;
	bool chechKingOnThrone()const;
	sf::RenderWindow m_gameWindow = { { 1920, 1080 }, "Save the king" };
	sf::Clock m_moveClock;
	sf::Time m_gameTime;
	sf::Text m_timeInfo;
	Window m_window;
	Board m_board;
	std::vector<std::unique_ptr<Players>> m_players;
	std::vector<std::unique_ptr<StaticObjects>> m_statics;
	int m_activePlayer;
};
