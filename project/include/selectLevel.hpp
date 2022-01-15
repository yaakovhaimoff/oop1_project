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

class SelectLevel
{
    public:
    SelectLevel();
    void setIsLevelSelect();
    int getLevelSelected() const { return m_levelSelected; }
    void setSelectLevel();
    void checkMouseOnLevelSelect(const sf::Event &);
    void checkLevelPressed(const sf::Vector2f &location);
    void drawSelectLevel(sf::RenderWindow &) const;

    private:
    sf::Text m_selectLevelText[AmountOfWindows];
    sf::Text m_selectLevelName;
    bool m_levelSelect = false;
	int m_levelSelected = 0;
};