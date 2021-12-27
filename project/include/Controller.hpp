#pragma once 

#include <stdio.h>
#include <iostream>
#include "macros.hpp"
#include "Window.hpp"
#include <SFML/Graphics.hpp>

class Controller
{
public:
	Controller();
	void runGame();
	void handleEvents();

private:
	sf::RenderWindow m_gameWindow = { { 1920, 1080 }, "Save the king" };
	Window m_window;

};
