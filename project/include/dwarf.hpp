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
    void moving(const sf::Time &, const sf::Event &, const bool);
    void setDirection();
    void collide(TeleporterObject &) override {}
    void collide(TimeGiftObject &) override {}
    void collide(RemoveDwarfsObject &) override {}

private:
    void saveAnimation(const sf::IntRect &currAnimation) { m_prevAnimation = currAnimation; }
    void newDirection(int);
    void updateAnimation();
    void updateCol() override;
    Direction m_dir;
    sf::IntRect m_prevAnimation;
    int m_keyDir;
    int m_row;
    int m_col;
};