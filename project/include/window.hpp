#pragma once

#include <iostream>
#include <stdio.h>
#include "macros.hpp"
#include <SFML/Graphics.hpp>

class Window
{
public:
	Window();
	void setMenu();
	void setHelp();
	void setPlay();
	void print(sf::RenderWindow&);
	void printMenu(sf::RenderWindow&);
	void printHelp(sf::RenderWindow&);
	void printPlay(sf::RenderWindow&);
	void handleClickInWindow(const sf::Vector2f&);
	void checkMenuPressed(const sf::Vector2f&);
	void checkHelpPressed(const sf::Vector2f&);
	bool isExit();

private:
	bool m_currentWindow[AmountOfWindows] = { true, false, false, false };
	sf::Texture m_texture[AmountOfWindows];
	sf::Sprite m_background[AmountOfWindows];
	sf::Font m_font;
	sf::Text m_gameName;
	sf::RectangleShape m_menuRects[AmountOfWindows - 1];
	sf::Text m_menuText[AmountOfWindows - 1];
	sf::RectangleShape m_helpRect;
	sf::Text m_helpText;
};
