#include "mage.hpp"
#include "warrior.hpp"
#include "thief.hpp"
#include "king.hpp"
#include "staticObjects.hpp"

void MageObject::collide(GameObjects& other)
{
	if (this == &other) return;
	other.collide(*this);
}
void MageObject::collide(KingObject& other)  { other.setPosition(); }
void MageObject::collide(WarriorObject& other) { other.setPosition(); }
void MageObject::collide(ThiefObject& other) { other.setPosition(); }

void MageObject::collide(WallObject&) { m_shape.setPosition(m_prev_location); }
void MageObject::collide(CrownObject&) { m_shape.setPosition(m_prev_location); }
void MageObject::collide(FireObject& other) { other.setIsDead(); }
void MageObject::collide(GateObject&) { m_shape.setPosition(m_prev_location); }
void MageObject::collide(MonsterObject&) { m_shape.setPosition(m_prev_location); }
void MageObject::collide(TeleporterObject&) {/*need to handle*/ }