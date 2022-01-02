#include "thief.hpp"
#include "king.hpp"
#include "mage.hpp"
#include "warrior.hpp"

void ThiefObject::collide(KingObject& other)  { other.setPosition(); }
void ThiefObject::collide(MageObject& other) { other.setPosition(); }
void ThiefObject::collide(WarriorObject& other) { other.setPosition(); }

void ThiefObject::collide(WallObject&) { m_shape.setPosition(m_prev_location); }
void ThiefObject::collide(CrownObject&) { m_shape.setPosition(m_prev_location); }
void ThiefObject::collide(FireObject&) { m_shape.setPosition(m_prev_location); }
void ThiefObject::collide(GateObject&)
{
	if (m_hasKey)
		m_hasKey = false;
	else
		m_shape.setPosition(m_prev_location);
}
void ThiefObject::collide(KeyObject&) { m_hasKey = true; }
void ThiefObject::collide(MonsterObject&) { m_shape.setPosition(m_prev_location); }
void ThiefObject::collide(TeleporterObject&) {/*need to handle*/ }
