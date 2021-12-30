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
	void move(sf::Time);
    sf::Vector2f getNextPosition(sf::Time);
    sf::Vector2f direction(sf::Time);

    enum class Direction
    {
        Stay,
        Up,
        Down,
        Left,
        Right,
    };
};
