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
	void setTime(const int);

private:
	void levelSelected();
	void handleGameOver();
	bool checkGameTime() const;
	void handleEvents();
	void exitGame(const sf::Event &);
	void mouseEventReleased(const sf::Event &);
	void keyboardEvent(const sf::Event &);
	void decideActivePlayer();
	void mouseEventMoved(const sf::Event &);
	void isPlaying(const sf::Event &);
	void playTime();
	void restartLevel();
	void drawGame();
	void setNextLevel();
	Window m_window;
	Data m_data;
	sf::RenderWindow m_gameWindow = {{1920, 1080}, "Save the king"};
	sf::Clock m_gameClock;
	sf::Clock m_moveClock;
	sf::Time pauseTime;
	sf::Text m_timeInfo;
	int m_gameTime =0;
	int m_activePlayer=0;
	int m_numOfLevel=0;
	bool isLevelSelected = true;
};