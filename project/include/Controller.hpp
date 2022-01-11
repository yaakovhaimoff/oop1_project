#pragma once 

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>

#include "Resources.hpp"
#include "macros.hpp"
#include "window.hpp"
#include "data.hpp"
#include "board.hpp"


class Controller 
{
public:
	Controller();
	void runGame();

private:
	void runLevel();
	void handleGameOver(const bool);
	bool checkGameTime()const;
	void handleEvents();
	void exitGame(const sf::Event&);
	void mouseEventReleased(const sf::Event&);
	void keyboardEvent(const sf::Event&);
	void decideActivePlayer();
	void mouseEventMoved(const sf::Event&);
	void isPlaying(const sf::Event&);
	void playTime();
	void restartLevel();
	sf::RenderWindow m_gameWindow = { { 1920, 1080 }, "Save the king" };
	sf::Clock m_gameClock;
	sf::Clock m_moveClock;
	int m_gameTime;
	sf::Time pauseTime;
	sf::Text m_timeInfo;
	Window m_window;
	Data m_data;
	int m_activePlayer;
	int m_numOfLevel;
	
};