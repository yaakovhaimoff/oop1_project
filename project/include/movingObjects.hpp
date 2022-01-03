#pragma once

#include <SFML/Graphics.hpp>

#include <stdio.h>
#include <string>
#include "gameObjects.hpp"

class MovingObjects : public GameObjects
{
public:
	MovingObjects(const sf::Vector2f& location, const int key) 
        : GameObjects(location, key) {}
    virtual void move(sf::Time) {};
    enum class Direction
    {
        Stay,
        Up,
        Down,
        Left,
        Right,
    };
};

class Players : public MovingObjects
{
public:
    Players(const sf::Vector2f& location, const int key)
        : MovingObjects(location, key) {}
    void move(sf::Time)override;
    void setPosition() { m_shape.setPosition(m_prev_location); }
protected:
    sf::Vector2f m_prev_location;
};

class Midgets : public MovingObjects
{
public:
    void move(sf::Time)override;
private:

};