#include "warrior.hpp"
#include "staticObjects.hpp"

void WarriorObject::collide(MonsterObject& other)
{
    Resources::instance().playSound(KillOrk);
    other.setIsDead(); 
}
