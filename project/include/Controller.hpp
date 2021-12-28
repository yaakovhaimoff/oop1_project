#pragma once 

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "macros.hpp"
#include "Window.hpp"
#include "GameObjects.hpp"
#include "Players.hpp"
#include "board.hpp"

class Controller
{
public:
	Controller();
	void runGame();
	void handleEvents();
	void drawGameWindow();

private:
	void findMovingPlayersLocation();
	int decideActivePlayer(int&);
	sf::RenderWindow m_gameWindow = { { 1920, 1080 }, "Save the king" };
	Window m_window;
	Board m_board;
	std::vector<std::unique_ptr<GameObjects>> m_players;
	sf::Clock m_gameClock;
	sf::Texture m_gameTexture;
	sf::Sprite m_gameSprite;
	int m_playersLocation[numOfPlayers];
	int m_activePlayer = KING_BOARD_OBJECT;
	int m_count = 0;
};
