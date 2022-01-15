#pragma once

#include "windowManager.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include "macros.hpp"
#include "Resources.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>

class HelpWindow
{
public:
    HelpWindow();
    void drawHelp(sf::RenderWindow &) const;
    void checkHelpPressed(const sf::Vector2f &);

private:
    void setHelp();
    sf::Text m_helpText;
};