#pragma once 

#include <SFML/Graphics.hpp>
#include <iostream>

#include "MovingObjects.hpp"
#include "macros.hpp"
//#include "mage.hpp"
//#include "warrior.hpp"
//#include "thief.hpp"
//class MageObject;
//class WarriorObject;
//class ThiefObject;


//_______________________________
class KingObject : public Players
{
public:
	KingObject(const sf::Vector2f& location, const int key)
		: Players(location, key), m_onCrown(false){}
	bool isKingOnThrone()const { return m_onCrown; }

	void collide(GameObjects& other)override
	{
		if (this == &other) return;
		other.collide(*this);
	}
	void collide(KingObject&) override { m_shape.setPosition(m_prev_location); }
	void collide(MageObject& /*other*/)override { /*other.collide(*this);*/ }
	void collide(WarriorObject& /*other*/)override { /*other.collide(*this);*/ }
	void collide(ThiefObject& /*other*/)override { /*other.collide(*this);*/ }

	void collide(WallObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(CrownObject&)override { std::cout << "you won!\n"; }
	void collide(FireObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(GateObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(KeyObject&)override {}
	void collide(MonsterObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(TeleporterObject&)override { /*need to handle*/ }
private:
	bool m_onCrown;

};