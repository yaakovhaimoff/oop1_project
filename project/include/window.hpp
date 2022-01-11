#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include "macros.hpp"
#include "Resources.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "movingObjects.hpp"
#include "staticObjects.hpp"

class Window
{
public:
	Window();
	void drawWindow(sf::RenderWindow &) const;
	void drawPlay(sf::RenderWindow &, const int&, const int, const bool, const bool, const int) const;
	void handleClickInWindow(const sf::Vector2f &);
	bool isPlaying() const;
	bool isPause()const;
	bool isExit() const;
	void catchMouseEvent(sf::RenderWindow &, const sf::Event &);

private:
	void setMenu();
	void setHelp();
	void setPlay();
	void setPause();
	void setActivePlayerInfo();
	void setPauseGame();
	void checkMouseOnMenu(const sf::Event &);
	void checkMouseOnBack(const sf::Event &);
	void checkMenuPressed(const sf::Vector2f &);
	void checkHelpPressed(const sf::Vector2f &);
	void checkPlayPressed(const sf::Vector2f &);
	void drawMenu(sf::RenderWindow &) const;
	void drawHelp(sf::RenderWindow &) const;
	void gameOverLevelMessage(sf::RenderWindow &) const;
	void drawLevelInfo(sf::RenderWindow &, const int &, const int, const bool) const;
	void drawActivePlayer(sf::RenderWindow&, const int)const;
	void drawPasuse(sf::RenderWindow&)const;
	void drawPasused(sf::RenderWindow&)const;
	bool m_currentWindow[AmountOfWindows+1] = {true, false, false, false};
	bool m_pauseButton;
	sf::Sprite m_background[AmountOfWindows];
	sf::Sprite m_gameSprite[LEVELS];
	sf::Sprite m_activePlayer[numOfPlayers];
	sf::Sprite m_pause;
	sf::Sprite m_paused;
	sf::Text m_gameName;
	sf::Text m_menuText[AmountOfWindows];
	sf::Text m_helpText;
	sf::Text m_infoText;
	sf::Text m_activePlayerText;
	sf::RectangleShape m_menuRects[AmountOfWindows];
	sf::RectangleShape m_helpRect;
	sf::RectangleShape m_infoRect;
};
