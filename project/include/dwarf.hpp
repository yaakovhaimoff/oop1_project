#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "movingObjects.hpp"
#include "macros.hpp"

class DwarfObject : public MovingObjects
{
public:
    DwarfObject(const sf::Vector2f &location, const int key)
        : MovingObjects(location, key) {}
    void move(sf::Time) override;
    void setDirection(int);
    sf::Clock getElapsedTimeToMove() const { m_canMove.getElapsedTime(); }

private:
    Direction m_dir;
    int m_random;
    sf::Clock m_canMove;
};