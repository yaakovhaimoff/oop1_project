#pragma once 

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "macros.hpp"
#include "Window.hpp"
#include "movingObjects.hpp"
#include "Players.hpp"

class Controller
{
public:
	Controller();
	void runGame();
	void handleEvents();

private:
	sf::RenderWindow m_gameWindow = { { 1920, 1080 }, "Save the king" };
	Window m_window;
	std::vector<std::unique_ptr<MovingObjects>> m_players;
	sf::Clock m_gameClock;

};
