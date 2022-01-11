#pragma once

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>

#include "macros.hpp"
#include "movingObjects.hpp"
#include "staticObjects.hpp"
#include "dwarf.hpp"
#include "board.hpp"

class Data
{
public:
    Data() = default;
    void setDataObjects();
    void setData(const sf::Vector2f &, const char);
    void clearObjects();
    void moveData(const sf::Event &, const sf::Time &, const int);
    bool wonLevel() const;
    void drawObjects(sf::RenderWindow &, const bool) const;
    bool thiefHasKey() const;
    bool endOfFile()const;
    void clearBoard();

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
    std::vector<std::unique_ptr<MovingObjects>> m_players;
    std::vector<std::unique_ptr<StaticObjects>> m_statics;
    std::vector<std::unique_ptr<TeleporterObject>> m_teleports;
    bool m_changeDwarfDir;
    int m_teleportIndex;
    int m_activePlayer;
    Board m_board;
};