#pragma once 

#include <SFML/Graphics.hpp>
#include "MovingObjects.hpp"
#include "macros.hpp"
//#include "thief.hpp"
//#include "king.hpp"
//#include "mage.hpp"
//class KingObject;
//class MageObject;
//class ThiefObject;

//__________________________________
class WarriorObject : public Players
{
public:
	WarriorObject(const sf::Vector2f& location, const char key)
		: Players(location, key) {}
	void collide(GameObjects& other)override
	{
		if (this == &other) return;
		other.collide(*this);
	}
	void collide(KingObject& /*other*/) override { /*other.collide(*this);*/ }
	void collide(MageObject& /*other*/)override { /*other.collide(*this);*/ }
	void collide(WarriorObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(ThiefObject& /*other*/)override { /*other.collide(*this);*/ }

	void collide(WallObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(CrownObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(FireObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(GateObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(KeyObject&)override {}
	void collide(MonsterObject&)override { /*need to handle*/ }
	void collide(TeleporterObject&)override { /*need to handle*/ }

};
