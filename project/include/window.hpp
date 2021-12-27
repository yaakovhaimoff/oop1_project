#pragma once

#include <iostream>
#include <stdio.h>
#include "macros.hpp"
#include <SFML/Graphics.hpp>

class Window
{
public:
	Window();
	void print(sf::RenderWindow&)const;
	void handleClickInWindow(const sf::Vector2f&);
	bool isPlaying()const;
	bool isExit()const;

private:
	void setMenu();
	void setHelp();
	void setPlay();
	void checkMenuPressed(const sf::Vector2f&);
	void checkHelpPressed(const sf::Vector2f&);
	void printMenu(sf::RenderWindow&)const;
	void printHelp(sf::RenderWindow&)const;
	void printPlay(sf::RenderWindow&)const;
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
