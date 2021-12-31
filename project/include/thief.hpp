#pragma once 

#include <SFML/Graphics.hpp>
#include <iostream>

#include "MovingObjects.hpp"
#include "macros.hpp"

//________________________________
class ThiefObject : public Players
{
public:
	ThiefObject(const sf::Vector2f& location, const char key)
		: Players("thief.png", location, key), m_hasKey(false) {}
	bool thiefHasKey()const { return m_hasKey; }
	void collide(GameObjects& other)override
	{
		if (this == &other) return;
		other.collide(*this);
	}
	void collide(KingObject&) override { m_shape.setPosition(m_prev_location); }
	void collide(MageObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(WarriorObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(ThiefObject& other)override { other.collide(*this); }

	void collide(WallObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(CrownObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(FireObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(GateObject&)override
	{
		if (m_hasKey)
			m_hasKey = false;
		else
			m_shape.setPosition(m_prev_location);
	}
	void collide(KeyObject&)override { m_hasKey = true; }
	void collide(MonsterObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(TeleporterObject&)override {/*need to handle*/ }

private:
	bool m_hasKey;

};
