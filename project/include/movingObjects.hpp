#pragma once

#include <SFML/Graphics.hpp>

#include <stdio.h>
#include <string>
#include "GameObjects.hpp"

class MovingObjects : public GameObjects
{
public:
	MovingObjects(const std::string fileName, const sf::Vector2f& location, const char key) 
        : GameObjects(fileName, location, key) {}
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
    Players(const std::string fileName, const sf::Vector2f& location, const char key)
        : MovingObjects(fileName, location, key) {}
    void move(sf::Time)override;
protected:
    sf::Vector2f m_prev_location;
};

class Midgets : public MovingObjects
{
public:
    void move(sf::Time)override;
private:

};