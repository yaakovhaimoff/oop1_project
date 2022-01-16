#include "movingInclude/mage.hpp"
#include "staticsInclude/fire.hpp"

//_________________________________________
void MageObject::collide(FireObject& other)
{
    Resources::instance().playSound(MageFire);
    other.setIsDead();
}
//______________________________________________________________________
void MageObject::move(const sf::Time &deltaTime, const sf::Event &event)
{
	getDir(event);
	setPrevPosition(getPosition());
	setMove(getDirFromKey() * mageSpeed * deltaTime.asSeconds());
}
