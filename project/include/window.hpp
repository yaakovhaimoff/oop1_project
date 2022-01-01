#pragma once

#include <iostream>
#include <stdio.h>
#include "macros.hpp"
#include "Resources.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Window
{
public:
	Window();
	void drawWindow(sf::RenderWindow&)const;
	void handleClickInWindow(const sf::Vector2f&);
	bool isPlaying()const;
	bool isExit()const;
	void catchMouseEvent(sf::RenderWindow&, const sf::Event&);

private:
	void setFont();
	void setSound();
	void setMenu();
	void setHelp();
	void checkMouseOnMenu(const sf::Event&);
	void checkMouseOnBack(const sf::Event&);
	void checkMenuPressed(const sf::Vector2f&);
	void checkHelpPressed(const sf::Vector2f&);
	void drawMenu(sf::RenderWindow&)const;
	void drawHelp(sf::RenderWindow&)const;

	bool m_currentWindow[AmountOfWindows] = { true, false, false, false };
	sf::Sound m_sounds[AmountOfSounds];
	sf::Sprite m_background[AmountOfWindows-1];
	sf::Font m_font;
	sf::Text m_gameName;
	sf::RectangleShape m_menuRects[AmountOfWindows - 1];
	sf::Text m_menuText[AmountOfWindows - 1];
	sf::RectangleShape m_helpRect;
	sf::Text m_helpText;
};
