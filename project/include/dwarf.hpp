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
    void move(const sf::Time&, const sf::Event&) override;
    void setDirection(int);
    int getElapsedTimeToMove() const { return m_canMove.getElapsedTime().asSeconds(); }

private:
    Direction m_dir;
    int m_random;
    sf::Clock m_canMove;
};