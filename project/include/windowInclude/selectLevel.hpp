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

class SelectLevel
{
    public:
    SelectLevel();
    void setSelectLevel();
    void checkMouseOnLevelSelect(const sf::Event &);
    void checkLevelPressed(const sf::Vector2f &location, WindowManager&);
    void drawSelectLevel(sf::RenderWindow &) const;
    int getLevelSelected() const { return m_levelSelected; }

    private:
    sf::Text m_selectLevelText[AmountOfWindows];
    sf::Text m_selectLevelName;
    bool m_levelSelect = false;
	int m_levelSelected = 0;
};