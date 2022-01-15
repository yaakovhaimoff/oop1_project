#pragma once

#include "gameObjects.hpp"
#include "macros.hpp"
#include "king.hpp"
#include "mage.hpp"
#include "warrior.hpp"
#include "thief.hpp"

//______________________________________
class StaticObjects : public GameObjects
{
public:
	StaticObjects(const sf::Vector2f &location, const int key)
		: GameObjects(location, key), m_isDeaed(false), m_col(0) {}
	bool isDead() { return m_isDeaed; }
	void setIsDead() { m_isDeaed = true; }
	void updateSpriteRect(const int, const float, const float, const float);

private:
	bool m_isDeaed;
	int m_col;
};