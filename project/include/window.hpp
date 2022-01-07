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
	void drawPlay(sf::RenderWindow &, const sf::Clock &, const sf::Time &, const int, const bool,
				  const std::vector<std::unique_ptr<MovingObjects>> &,
				  const std::vector<std::unique_ptr<StaticObjects>> &,
				  const std::vector<std::unique_ptr<TeleporterObject>> &, const bool) const;
	void handleClickInWindow(const sf::Vector2f &);
	bool isPlaying() const;
	void setIsPlaying();
	bool isExit() const;
	void catchMouseEvent(sf::RenderWindow &, const sf::Event &);
	void restartLevelMessage(sf::RenderWindow &) const;

private:
	void setMenu();
	void setHelp();
	void setPlay();
	void checkMouseOnMenu(const sf::Event &);
	void checkMouseOnBack(const sf::Event &);
	void checkMenuPressed(const sf::Vector2f &);
	void checkHelpPressed(const sf::Vector2f &);
	void drawMenu(sf::RenderWindow &) const;
	void drawHelp(sf::RenderWindow &) const;
	void drawObjects(sf::RenderWindow &,
					 const std::vector<std::unique_ptr<MovingObjects>> &,
					 const std::vector<std::unique_ptr<StaticObjects>> &,
					 const std::vector<std::unique_ptr<TeleporterObject>> &) const;
	void drawLevelInfo(sf::RenderWindow &, const sf::Clock &, const sf::Time &, const int, const bool) const;
	bool m_currentWindow[AmountOfWindows+1] = {true, false, false, false};
	sf::Sprite m_background[AmountOfWindows];
	sf::Sprite m_gameSprite[LEVELS];
	sf::Text m_gameName;
	sf::Text m_menuText[AmountOfWindows];
	sf::Text m_helpText;
	sf::Text m_infoText;
	sf::RectangleShape m_menuRects[AmountOfWindows];
	sf::RectangleShape m_helpRect;
	sf::RectangleShape m_infoRect;
};
