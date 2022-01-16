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

class HelpWindow
{
public:
    HelpWindow();
    void drawHelp(sf::RenderWindow &) const;
    void checkMouseOnBack(const sf::Event &);
    void checkHelpPressed(const sf::Vector2f &, WindowManager &);

private:
    void setHelp();
    sf::Text m_helpText;
};