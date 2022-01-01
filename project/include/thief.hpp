#pragma once 

#include <SFML/Graphics.hpp>
#include <iostream>

#include "MovingObjects.hpp"
#include "macros.hpp"
//#include "king.hpp"
//#include "mage.hpp"
//#include "warrior.hpp"
//class KingObject;
//class MageObject;
//class WarriorObject;

//________________________________
class ThiefObject : public Players
{
public:
	ThiefObject(const sf::Vector2f& location, const char key)
		: Players(location, key), m_hasKey(false) {}
	bool thiefHasKey()const { return m_hasKey; }
	void collide(GameObjects& other)override
	{
		if (this == &other) return;
		other.collide(*this);
	}
	void collide(KingObject& /*other*/) override { /*other.collide(*this);*/ }
	void collide(MageObject& /*other*/)override { /*other.collide(*this);*/ }
	void collide(WarriorObject& /*other*/)override { /*other.collide(*this);*/ }
	void collide(ThiefObject&)override { m_shape.setPosition(m_prev_location); }

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
