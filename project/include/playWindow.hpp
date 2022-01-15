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

class PlayWindow
{
public:
    PlayWindow();
    void drawPauseMessage(sf::RenderWindow &);
    void drawPlayWindow(sf::RenderWindow &, const int &,
                        const int, const bool, const int) const;
    void gameOverLevelMessage(sf::RenderWindow &) const;
    void winLevelMessage(sf::RenderWindow &) const;
    bool isPlaying() const;
    bool isPause() const;
    void checkPausePressed(const sf::Vector2f &);
    void checkSoundPressed(const sf::Vector2f &);
    void checkPlayPressed(const sf::Vector2f &);
    void drawLevelInfo(sf::RenderWindow &, const int &,
                       const int, const bool) const;
    void drawActivePlayer(sf::RenderWindow &, const int) const;
    void drawPasuse(sf::RenderWindow &) const;
    void drawPasused(sf::RenderWindow &) const;

private:
    void setPlay();
    void setPlay();
    void setPause();
    void setSound();
    void setActivePlayerInfo();
    void setPauseGame();
    bool m_pauseButton;
    bool m_soundButton;
    sf::Sprite m_gameSprite[LEVELS];
    sf::Sprite m_pause;
    sf::Sprite m_paused;
    sf::Sprite m_sound;
    sf::Sprite m_key;
    sf::Sprite m_noKey;
    sf::Sprite m_activePlayer[numOfPlayers];
    sf::Text m_infoText;
    sf::Text m_activePlayerText;
    sf::RectangleShape m_infoRect;
};