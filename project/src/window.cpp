#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>


#include "window.hpp"

//________________________
Window::Window()
{
	m_currentWindow[PLAY] = false;
	m_currentWindow[EXIT] = false;
	m_font.loadFromFile("font.ttf");
	this->setTexture();
	this->setBackground();
	this->setMenu();
	this->setHelp();
}
//____________________
void Window::setMenu()
{
	m_currentWindow[MENU] = true;
	m_texture[MENU].loadFromFile("menu.png");
	m_background[MENU].setTexture(m_texture[MENU]);
	// set rectangle for the menu buttons and texts
	for (int row = 1; row < AmountOfWindows; row++)
	{
		m_menuRects[row-1] = sf::RectangleShape({ 220, 120 });
		m_menuRects[row - 1].setFillColor(sf::Color(0, 0, 0, 3));
		m_menuRects[row - 1].setOutlineColor(sf::Color::White);
		m_menuRects[row - 1].setOutlineThickness(4);
		m_menuRects[row - 1].setPosition(sf::Vector2f((CELL + SPACE) * row, SPACE + 100));

		m_menuText[row - 1].setFont(m_font);
		m_menuText[row - 1].setCharacterSize(100);
		m_menuText[row - 1].setFillColor(sf::Color::White);
		m_menuText[row - 1].setPosition(sf::Vector2f((CELL + SPACE + 4) * row, SPACE + 100));
		m_menuText[row - 1].setString(menu_names[row - 1]);
	}
	sf::Text menuButtonText;
	// set the game name 
	m_gameName.setFont(m_font);
	m_gameName.setCharacterSize(150);
	m_gameName.setFillColor(sf::Color::White);
	m_gameName.setPosition(sf::Vector2f(560, 100));
	m_gameName.setString("SAVE THE KING");
}
//____________________
void Window::setHelp()
{
	m_currentWindow[HELP] = false;
	m_texture[HELP].loadFromFile("help.png");
	m_background[HELP].setTexture(m_texture[HELP]);
	// set rectangle for the help back button
	m_helpRect = sf::RectangleShape({ 160, 90 });
	m_helpRect.setFillColor(sf::Color(0, 0, 0, 3));
	m_helpRect.setOutlineColor(sf::Color::White);
	m_helpRect.setOutlineThickness(4);
	m_helpRect.setPosition(sf::Vector2f(20, 20));
	// set back string text
	m_helpText.setFont(m_font);
	m_helpText.setCharacterSize(80);
	m_helpText.setFillColor(sf::Color::White);
	m_helpText.setPosition(sf::Vector2f(25, 20));
	m_helpText.setString("BACK");
}
//_______________________
void Window::setTexture()
{
	m_texture[PLAY].loadFromFile("play.png");
}
//_________________________
void Window::setBackground()
{
	m_background[PLAY].setTexture(m_texture[PLAY]);
}
//__________________________
void Window::manageWindow()
{
	while (m_window.isOpen())
	{
		this->print();
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseButtonReleased:
			{
				// getting the location of where the mouse was pressed
				auto location = m_window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				handleClickInWindow(location);
			}
			}
		}
	}
}
//___________________________________________________________
void Window::handleClickInWindow(const sf::Vector2f& location)
{
	if (m_currentWindow[MENU])
		this->checkMenuPressed(location);
	else if (m_currentWindow[HELP])
		this->checkHelpPressed(location);
	
}
//_________________________________________________________
void Window::checkMenuPressed(const sf::Vector2f& location)
{
	auto menuButton = sf::RectangleShape({ 220, 120 });

	for (int row = 1; row < AmountOfWindows; row++)
	{
		menuButton.setPosition(sf::Vector2f((CELL + SPACE) * row, SPACE + 100));

		if (menuButton.getGlobalBounds().contains(location))
		{
			m_currentWindow[MENU] = false;
			m_currentWindow[row] = true;
			break;
		}
	}
}
//_________________________________________________________
void Window::checkHelpPressed(const sf::Vector2f& location)
{
	auto backButton = sf::RectangleShape({ 160, 90 });
	backButton.setPosition(sf::Vector2f(20, 20));
	if (backButton.getGlobalBounds().contains(location))
	{
		m_currentWindow[HELP] = false;
		m_currentWindow[MENU] = true;
	}
}
//__________________
void Window::print()
{
	if (m_currentWindow[MENU])
		this->printMenu();
	else if (m_currentWindow[HELP])
		this->printHelp();
	else if (m_currentWindow[PLAY])
		this->printPlay();
}
//______________________
void Window::printMenu()
{
	m_window.clear();
	m_window.draw(m_background[MENU]);
	m_window.draw(m_gameName);
	for (int row = 1; row < AmountOfWindows; row++)
	{
		m_window.draw(m_menuRects[row-1]);
		m_window.draw(m_menuText[row-1]);
	}
	m_window.display();
}
//______________________
void Window::printHelp()
{
	m_window.clear();
	m_window.draw(m_background[HELP]);
	m_window.draw(m_helpRect);
	m_window.draw(m_helpText);
	m_window.display();
}
//______________________
void Window::printPlay()
{
	m_window.clear();
	m_window.draw(m_background[PLAY]);
	m_window.display();
}