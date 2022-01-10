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
	void movePlayerObject(const sf::Event&, const sf::Time&);
	void moveDwarfsObjects(const sf::Event&, const sf::Time&);
	void checkDwarfCollision(const sf::Event&);
	void checkPlayerCollision(MovingObjects&);
	void checkToOpenTeleport(MovingObjects &activePlayer);
	bool noOtherPlayerIsOnNextTeleport(const int)const;
	void handleDaedObjects();
	bool wonLevel()const;
	void restartLevel();
	void clearObjects();
	int getTimeForGift();
	void removeDwarfs();
	sf::RenderWindow m_gameWindow = { { 1920, 1080 }, "Save the king" };
	sf::Clock m_gameClock;
	sf::Clock m_moveClock;
	static sf::Clock m_moveDwarf;
	int m_gameTime;
	sf::Time pauseTime;
	sf::Text m_timeInfo;
	Window m_window;
	Board m_board;
	std::vector<std::unique_ptr<MovingObjects>> m_players;
	std::vector<std::unique_ptr<StaticObjects>> m_statics;
	std::vector<std::unique_ptr<TeleporterObject>> m_teleports;
	int m_activePlayer;
	int m_teleportIndex;
	int m_numOfLevel;
	bool m_changeDwarfDir;
};