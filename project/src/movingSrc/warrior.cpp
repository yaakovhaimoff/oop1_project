#include "movingInclude/warrior.hpp"
#include "staticsInclude/monster.hpp"

//_______________________________________________
void WarriorObject::collide(MonsterObject& other)
{
    Resources::instance().playSound(KillOrk);
    other.setIsDead(); 
}
//_________________________________________________________________________
void WarriorObject::move(const sf::Time &deltaTime, const sf::Event &event)
{
	getDir(event);
	setPrevPosition(getPosition());
	setMove(getDirFromKey() * warriorSpeed * deltaTime.asSeconds());
}
