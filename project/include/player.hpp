#pragma once 

#include <SFML/Graphics.hpp>
#include <iostream>

#include "movingObjects.hpp"
#include "macros.hpp"

class Player : public MovingObjects
{
    public:
	Player(const sf::Vector2f& location, const int key)
		: MovingObjects(location, key){}
};