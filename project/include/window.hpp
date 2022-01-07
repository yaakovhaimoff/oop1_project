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
	void drawWindow(sf::RenderWindow&)const;
	void drawPlay(sf::RenderWindow&, const sf::Clock&, const sf::Time&, const int, const bool,
		const std::vector<std::unique_ptr<MovingObjects>>&,
		const std::vector<std::unique_ptr<StaticObjects>>&,
		const std::vector<std::unique_ptr<TeleporterObject>>&)const;
	void handleClickInWindow(const sf::Vector2f&);
	bool isPlaying()const;
	void setIsPlaying();
	bool isExit()const;
	void catchMouseEvent(sf::RenderWindow&, const sf::Event&);

private:
	void setFont();
	void setSound();
	void setMenu();
	void setHelp();
	void setPlay();
	void checkMouseOnMenu(const sf::Event&);
	void checkMouseOnBack(const sf::Event&);
	void checkMenuPressed(const sf::Vector2f&);
	void checkHelpPressed(const sf::Vector2f&);
	void drawMenu(sf::RenderWindow&)const;
	void drawHelp(sf::RenderWindow&)const;
	void drawObjects(sf::RenderWindow&,
		const std::vector<std::unique_ptr<MovingObjects>>&,
		const std::vector<std::unique_ptr<StaticObjects>>&,
		const std::vector<std::unique_ptr<TeleporterObject>>&)const;
	void drawLevelInfo(sf::RenderWindow&, const sf::Clock&, const sf::Time&, const int, const bool)const;
	bool m_currentWindow[AmountOfWindows] = { true, false, false, false };
	sf::Sound m_sounds[AmountOfSounds];
	sf::Sprite m_background[AmountOfWindows - 1];
	sf::Font m_font;
	sf::Text m_gameName;
	sf::RectangleShape m_menuRects[AmountOfWindows - 1];
	sf::Text m_menuText[AmountOfWindows - 1];
	sf::RectangleShape m_helpRect;
	sf::Text m_helpText;
	sf::Sprite m_gameSprite;
	sf::RectangleShape m_infoRect;
	sf::Text m_infoText;
};
