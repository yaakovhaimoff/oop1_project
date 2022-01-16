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

#include "helpWindow.hpp"
#include "menuWindow.hpp"
#include "selectLevel.hpp"
#include "playWindow.hpp"

class WindowManager
{
public:
    WindowManager();
    void drawWindow(sf::RenderWindow &) const;
    void handleClickInWindow(const sf::Vector2f &);
    void catchMouseEvent(sf::RenderWindow &, const sf::Event &);
    bool isPlaying() const;
    bool isPause() const;
    bool isExit() const;
    void setWindow(const int, const int);
    int getLevelSelected()const{return m_selectLevel.getLevelSelected();}
    void winLevelMessage(sf::RenderWindow &)const;
    void gameOverLevelMessage(sf::RenderWindow &)const;
    void drawPauseMessage(sf::RenderWindow &)const;
    void drawPlayWindow(sf::RenderWindow &, const int &,
                        const int, const bool, const int) const;

private:
    bool m_currentWindow[AmountOfWindows + 1] = {true, false, false, false, false};
    HelpWindow m_helpWindow;
    MenuWindow m_menuWindow;
    SelectLevel m_selectLevel;
    PlayWindow m_playWindow;
};