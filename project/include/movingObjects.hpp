#pragma once

#include <stdio.h>
#include <string>
#include "GameObjects.hpp"

class MovingObjects : public GameObjects
{
public:
	MovingObjects(std::string fileName, sf::Vector2f location) : GameObjects(fileName, location) {}
	void move(sf::Time);

    enum class Direction
    {
        Stay,
        Up,
        Down,
        Left,
        Right,
    };
};
