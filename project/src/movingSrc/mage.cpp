#include "movingInclude/mage.hpp"
#include "staticsInclude/fire.hpp"

void MageObject::collide(FireObject& other)
{
    Resources::instance().playSound(MageFire);
    other.setIsDead();
}
//_________________________________________________________________________
void MageObject::move(const sf::Time &deltaTime, const sf::Event &event)
{
	getDir(event);
	setPrevPosition(getPosition());
	setMove(getDirFromKey() * mageSpeed * deltaTime.asSeconds());
}
