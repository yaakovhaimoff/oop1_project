#include "thief.hpp"
#include "king.hpp"
#include "mage.hpp"
#include "warrior.hpp"
#include "staticObjects.hpp"

void ThiefObject::collide(GameObjects& other)
{
	if (this == &other) return;
	other.collide(*this);
}
void ThiefObject::collide(KingObject& other) { other.setPosition(); }
void ThiefObject::collide(MageObject& other) { other.setPosition(); }
void ThiefObject::collide(WarriorObject& other) { other.setPosition(); }

void ThiefObject::collide(WallObject&) { m_shape.setPosition(m_prev_location); }
void ThiefObject::collide(CrownObject&) { m_shape.setPosition(m_prev_location); }
void ThiefObject::collide(FireObject&) { m_shape.setPosition(m_prev_location); }
void ThiefObject::collide(GateObject& other)
{
	if (m_hasKey>0)
	{
		other.setIsDead();
		m_hasKey = 0;
	}
	else
		m_shape.setPosition(m_prev_location);
}
void ThiefObject::collide(KeyObject& other)
{
	if (m_hasKey==0)
		other.setIsDead();
	m_hasKey++;
}
void ThiefObject::collide(MonsterObject&) { m_shape.setPosition(m_prev_location); }
void ThiefObject::collide(TeleporterObject& other) { m_shape.setPosition(other.getPosition()); }

// 1 2 3 0 4 5