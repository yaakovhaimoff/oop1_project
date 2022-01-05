#pragma once

#include <SFML/Graphics.hpp>

#include <stdio.h>
#include <string>
#include "gameObjects.hpp"

class TeleporterObject;

class MovingObjects : public GameObjects
{
public:
    MovingObjects(const sf::Vector2f &location, const int key)
        : GameObjects(location, key) {}
    virtual void move(sf::Time);
    void setPosition() { m_shape.setPosition(m_prev_location); }
    sf::Vector2f getPrevPosition() const { return m_prev_location; }
    void setDwarf(const sf::Vector2f& location){m_prev_location = m_shape.getPosition();}
    
    void collide(GameObjects &) override;
    void collide(KingObject &) override {}
    void collide(MageObject &) override {}
    void collide(WarriorObject &) override {}
    void collide(ThiefObject &) override {}
    void collide(DwarfObject &) override {}

    void collide(WallObject &) override;
    void collide(CrownObject &) override;
    void collide(FireObject &) override;
    void collide(GateObject &) override;
    void collide(KeyObject &) override;
    void collide(MonsterObject &) override;
    void collide(TeleporterObject &) override;

    enum class Direction
    {
        Stay,
        Up,
        Down,
        Left,
        Right,
    };

private:
    sf::Vector2f m_prev_location;
};

