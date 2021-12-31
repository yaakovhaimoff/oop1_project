#pragma once 

#include <SFML/Graphics.hpp>
#include <iostream>

#include "MovingObjects.hpp"
#include "macros.hpp"

//_______________________________
class KingObject : public Players
{
public:
	KingObject(const sf::Vector2f& location, const char key)
		: Players("king.png", location, key), m_onCrown(false){}
	bool isKingOnThrone()const { return m_onCrown; }

	void collide(GameObjects& other)override
	{
		if (this == &other) return;
		other.collide(*this);
	}
	void collide(KingObject& other) override { other.collide(*this); }
	void collide(MageObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(WarriorObject&)override { m_shape.setPosition(m_prev_location); }
	void collide(ThiefObject&)override { m_shape.setPosition(m_prev_location); }

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