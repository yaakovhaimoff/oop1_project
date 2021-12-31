#pragma once 

#include <SFML/Graphics.hpp>
#include "MovingObjects.hpp"
#include "macros.hpp"

//_______________________________
class MageObject : public Players
{
public:
	MageObject(const sf::Vector2f& location, const char key)
		: Players("mage.png", location, key) {}
	void collide(GameObjects& other)override
	{
		if (this == &other) return;
		other.collide(*this);
	}
	void collide(KingObject&) override { m_shape.setPosition(m_prev_location); }
	void collide(MageObject& other)override { other.collide(*this); }
	void collide(WarriorObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(ThiefObject&)override { m_shape.setPosition(m_prev_location); }

	void collide(WallObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(CrownObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(FireObject&)override { /*delete fire*/ }
	void collide(GateObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(KeyObject&)override {};
	void collide(MonsterObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(TeleporterObject&)override {/*need to handle*/ }

};