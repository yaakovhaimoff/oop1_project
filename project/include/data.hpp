#pragma once

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>

#include "macros.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "staticObjects.hpp"
#include "dwarf.hpp"
#include "board.hpp"

class Controller;

class Data
{
public:
    Data(Controller &);
    void setDataToLevelStart(const int);
    void setDataToLevelRestart(const int);
    void setData(const sf::Vector2f &, const char);
    void clearObjects();
    void moveData(const sf::Event &, const sf::Time &, const int);
    bool wonLevel() const;
    void drawObjects(sf::RenderWindow &, const bool, const bool) const;
    bool thiefHasKey() const;
    bool endOfFile() const;
    void clearBoard();
    int getLevelTime(const int level) const { return m_board.getLevelTime(level); }

private:
    void connectToTeleports();
    void movePlayerObject(const sf::Event &, const sf::Time &);
    void moveDwarfsObjects(const sf::Event &, const sf::Time &);
    void checkDwarfCollision(const sf::Event &);
    void checkPlayerCollision(MovingObjects &);
    void checkToOpenTeleport(MovingObjects &activePlayer);
    bool noOtherPlayerIsOnNextTeleport(const int) const;
    void handleDaedObjects();
    void removeDwarfs();
    int getTimeForGift();
    std::vector<std::unique_ptr<Player>> m_players;
    std::vector<std::unique_ptr<Enemy>> m_dwarfs;
    std::vector<std::unique_ptr<StaticObjects>> m_statics;
    std::vector<std::unique_ptr<TeleporterObject>> m_teleports;
    bool m_changeDwarfDir = false;
    int m_teleportIndex = 0;
    int m_activePlayer = 0;
    Board m_board;
    Controller *m_controller;
};