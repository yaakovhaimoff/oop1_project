#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include "macros.hpp"
#include "Resources.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>

class WindowManager;

class MenuWindow
{
public:
    MenuWindow();
    void checkMouseOnMenu(const sf::Event &);
    void checkMenuPressed(const sf::Vector2f &, WindowManager&);
    void drawMenu(sf::RenderWindow &) const;

private:
    void setMenu();
    sf::Text m_menuText[AmountOfWindows];
    sf::Text m_gameName;
};