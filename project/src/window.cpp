#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>


#include "window.hpp"

//________________________
Window::Window()
//	: m_currentWindow({ true, false, false })
{
	m_currentWindow[MENU] = true;
	m_currentWindow[HELP] = false;
	m_currentWindow[PLAY] = false;
	m_currentWindow[EXIT] = false;
	this->setTexture();
	this->setBackground();
	m_font.loadFromFile("font.ttf");
}
//_______________________
void Window::setTexture()
{
	m_texture[MENU].loadFromFile("menu.png");
	m_texture[HELP].loadFromFile("help.png");
	m_texture[PLAY].loadFromFile("play.png");
}
//_________________________
void Window::setBackground()
{
	m_background[MENU].setTexture(m_texture[MENU]);
	m_background[HELP].setTexture(m_texture[HELP]);
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
	// set rectangle for the menu button
	auto menuButton = sf::RectangleShape({ 220, 120 });
	menuButton.setFillColor(sf::Color(0, 0, 0, 3));
	menuButton.setOutlineColor(sf::Color::White);
	menuButton.setOutlineThickness(4);

	sf::Text menuButtonText, gameName;
	// set the game name 
	gameName.setFont(m_font);
	gameName.setCharacterSize(150);
	gameName.setFillColor(sf::Color::White);
	gameName.setPosition(sf::Vector2f(560, 100));
	gameName.setString("SAVE THE KING");
	// set the text for the menu button
	menuButtonText.setFont(m_font);
	menuButtonText.setCharacterSize(100);
	menuButtonText.setFillColor(sf::Color::White);

	m_window.clear();
	m_window.draw(m_background[MENU]);
	m_window.draw(gameName);
	for (int row = 1; row < AmountOfWindows; row++)
	{
		menuButton.setPosition(sf::Vector2f((CELL + SPACE) * row, SPACE + 100));
		menuButtonText.setPosition(sf::Vector2f((CELL + SPACE + 4) * row, SPACE + 100));
		menuButtonText.setString(menu_names[row - 1]);
		m_window.draw(menuButtonText);
		m_window.draw(menuButton);
	}
	m_window.display();
}
//______________________
void Window::printHelp()
{
	// set rectangle for the help back button
	auto backButton = sf::RectangleShape({ 160, 90 });
	backButton.setFillColor(sf::Color(0, 0, 0, 3));
	backButton.setOutlineColor(sf::Color::White);
	backButton.setOutlineThickness(4);
	backButton.setPosition(sf::Vector2f(20, 20));
	// set the game name 
	sf::Text back;
	back.setFont(m_font);
	back.setCharacterSize(80);
	back.setFillColor(sf::Color::White);
	back.setPosition(sf::Vector2f(25, 20));
	back.setString("BACK");

	m_window.clear();
	m_window.draw(m_background[HELP]);
	m_window.draw(backButton);
	m_window.draw(back);
	m_window.display();
}
//______________________
void Window::printPlay()
{
	m_window.clear();
	m_window.draw(m_background[PLAY]);
	m_window.display();
}