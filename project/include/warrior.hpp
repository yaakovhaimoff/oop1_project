#pragma once 

#include <SFML/Graphics.hpp>
#include "MovingObjects.hpp"
#include "macros.hpp"

//__________________________________
class WarriorObject : public Players
{
public:
	WarriorObject(const sf::Vector2f& location, const char key)
		: Players("warrior.png", location, key) {}
	void collide(GameObjects& other)override
	{
		if (this == &other) return;
		other.collide(*this);
	}
	void collide(KingObject&) override { m_shape.setPosition(m_prev_location); }
	void collide(MageObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(WarriorObject& other)override { other.collide(*this); }
	void collide(ThiefObject&)override { m_shape.setPosition(m_prev_location); }

	void collide(WallObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(CrownObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(FireObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(GateObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(KeyObject&)override {}
	void collide(MonsterObject&)override { /*need to handle*/ }
	void collide(TeleporterObject&)override { /*need to handle*/ }

};
