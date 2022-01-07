#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "movingObjects.hpp"
#include "macros.hpp"

class DwarfObject : public MovingObjects
{
public:
    DwarfObject(const sf::Vector2f &location, const int key)
        : MovingObjects(location, key), m_keyDir(0), m_row(0), m_col(0) {}
    void move(const sf::Time&, const sf::Event&) override;
    void setDirection(int);
    //void updateAnimation();
    // void updateCol();

private:
    Direction m_dir;
    int m_random;
    sf::Clock m_canMove;
    int m_keyDir;
    int m_row;
    int m_col;
};