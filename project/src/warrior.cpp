#include "warrior.hpp"
#include "thief.hpp"
#include "king.hpp"
#include "mage.hpp"

void WarriorObject::collide(KingObject& other)  { other.setPosition(); }
void WarriorObject::collide(MageObject& other) { other.setPosition(); }
void WarriorObject::collide(ThiefObject& other) { other.setPosition(); }

void WarriorObject::collide(WallObject&) { m_shape.setPosition(m_prev_location); }
void WarriorObject::collide(CrownObject&) { m_shape.setPosition(m_prev_location); }
void WarriorObject::collide(FireObject&) { m_shape.setPosition(m_prev_location); }
void WarriorObject::collide(GateObject&) { m_shape.setPosition(m_prev_location); }
void WarriorObject::collide(MonsterObject&) { /*need to handle*/ }
void WarriorObject::collide(TeleporterObject&) { /*need to handle*/ }