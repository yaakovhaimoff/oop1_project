#pragma once 

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "macros.hpp"
#include "Window.hpp"
#include "movingObjects.hpp"
#include "staticObjects.hpp"
#include "Players.hpp"
#include "board.hpp"

class Controller
{
public:
	Controller();
	void runGame();

private:
	void handleEvents();
	void drawGameWindow();
	void drawObjects();
	void exitGame(const sf::Event&);
	void mouseEventReleased(const sf::Event&);
	void keyboardEvent(const sf::Event&);
	void decideActivePlayer();
	void mouseEventMoved(const sf::Event&);
	void isPlaying();
	sf::RenderWindow m_gameWindow = { { 1920, 1080 }, "Save the king" };
	Window m_window;
	Board m_board;
	std::vector<std::unique_ptr<MovingObjects>> m_players;
	std::vector<std::unique_ptr<StaticObjects>> m_statics;
	sf::Clock m_gameClock;
	sf::Texture m_gameTexture;
	sf::Sprite m_gameSprite;
	int m_activePlayer;
};
