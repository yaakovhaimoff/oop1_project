#include "warrior.hpp"
#include "staticObjects.hpp"

void WarriorObject::collide(MonsterObject& other) { other.setIsDead(); }
