#pragma once

#include <iostream>
#include <stdio.h>
#include "macros.hpp"
#include <SFML/Graphics.hpp>

class Window
{
public:
	Window();
	void drawWindow(sf::RenderWindow&)const;
	void handleClickInWindow(const sf::Vector2f&);
	bool isPlaying()const;
	bool isExit()const;

private:
	void setMenu();
	void setHelp();
	void checkMenuPressed(const sf::Vector2f&);
	void checkHelpPressed(const sf::Vector2f&);
	void drawMenu(sf::RenderWindow&)const;
	void drawHelp(sf::RenderWindow&)const;

	bool m_currentWindow[AmountOfWindows] = { true, false, false, false };
	sf::Texture m_texture[AmountOfWindows-1];
	sf::Sprite m_background[AmountOfWindows-1];
	sf::Font m_font;
	sf::Text m_gameName;
	sf::RectangleShape m_menuRects[AmountOfWindows - 1];
	sf::Text m_menuText[AmountOfWindows - 1];
	sf::RectangleShape m_helpRect;
	sf::Text m_helpText;
};
