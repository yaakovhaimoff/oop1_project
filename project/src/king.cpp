#include "king.hpp"
#include "warrior.hpp"
#include "mage.hpp"
#include "thief.hpp"
#include "staticObjects.hpp"

void KingObject::collide(GameObjects& other)
{
	if (this == &other) return;
	other.collide(*this);
}
void KingObject::collide(MageObject& other) { other.setPosition(); }
void KingObject::collide(WarriorObject& other) { other.setPosition(); }
void KingObject::collide(ThiefObject& other) { other.setPosition(); }

void KingObject::collide(WallObject&) { m_shape.setPosition(m_prev_location); }
void KingObject::collide(CrownObject& other) { other.setIsDead(); }
void KingObject::collide(FireObject&) { m_shape.setPosition(m_prev_location); }
void KingObject::collide(GateObject&) { m_shape.setPosition(m_prev_location); }
void KingObject::collide(KeyObject&) {}
void KingObject::collide(MonsterObject&) { m_shape.setPosition(m_prev_location); }
void KingObject::collide(TeleporterObject&) { /*need to handle*/ }