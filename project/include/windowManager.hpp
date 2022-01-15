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
    void setWindow(const bool, const bool, const int, const int);

private:
    void checkMouseOnMenu(const sf::Event &);
    void checkMouseOnBack(const sf::Event &);
    void checkMouseOnLevelSelect(const sf::Event &);
    bool m_currentWindow[AmountOfWindows + 1] = {true, false, false, false};
    HelpWindow m_helpWindow;
    MenuWindow m_menuWindow;
    SelectLevel m_selectLevel;
    PlayWindow m_playWindow;
};