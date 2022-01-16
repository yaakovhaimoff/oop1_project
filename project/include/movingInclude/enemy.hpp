#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "movingObjects.hpp"
#include "macros.hpp"

class Enemy : public MovingObjects
{
public:
	Enemy(const sf::Vector2f &location, const int key)
		: MovingObjects(location, key), m_isDeaed(false) {}
	bool isDead() { return m_isDeaed; }
	void setIsDead() { m_isDeaed = true; }

private:
	bool m_isDeaed = false;
};