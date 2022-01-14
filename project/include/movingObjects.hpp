#pragma once

#include <SFML/Graphics.hpp>

#include <stdio.h>
#include <string>
#include "gameObjects.hpp"

class TeleporterObject;
class TimeGiftObject;
class RemoveDwarfsObject;

class MovingObjects : public GameObjects
{
public:
    MovingObjects(const sf::Vector2f &location, const int key)
        : GameObjects(location, key), m_keyDir(0), m_row(0), m_col(0) {}
    virtual void move(const sf::Time &, const sf::Event &){}
    void setPrevPosition(const sf::Vector2f& location) { m_prev_location = location; }
    void setPosition() { setSprite(m_prev_location); }
    void getDir(const sf::Event &);
    virtual void updateCol();
    sf::Vector2f getPrevPosition() const { return m_prev_location; }
    sf::Vector2f getDirFromKey()const;

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
    void collide(TimeGiftObject &) override;
	void collide(RemoveDwarfsObject &) override;

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
    int m_keyDir;
    int m_row;
    int m_col;
};
