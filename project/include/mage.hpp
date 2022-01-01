#pragma once 

#include <SFML/Graphics.hpp>
#include "MovingObjects.hpp"
#include "macros.hpp"
//#include "warrior.hpp"
//#include "thief.hpp"
//#include "king.hpp"
//class KingObject;
//class WarriorObject;
//class ThiefObject;

//_______________________________
class MageObject : public Players
{
public:
	MageObject(const sf::Vector2f& location, const char key)
		: Players(location, key) {}
	void collide(GameObjects& other)override
	{
		if (this == &other) return;
		other.collide(*this);
	}
	void collide(KingObject& /*other*/) override { /*other.collide(*this);*/ }
	void collide(MageObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(WarriorObject& /*other*/)override { /*other.collide(*this);*/ }
	void collide(ThiefObject& /*other*/)override { /*other.collide(*this);*/ }

	void collide(WallObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(CrownObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(FireObject& /*other*/)override { /*other.setIsDead();*/ }
	void collide(GateObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(KeyObject&)override {};
	void collide(MonsterObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(TeleporterObject&)override {/*need to handle*/ }

};