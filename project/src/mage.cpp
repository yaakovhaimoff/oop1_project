#include "mage.hpp"
#include "staticObjects.hpp"

void MageObject::collide(FireObject& other)
{
    Resources::instance().playSound(MageFire);
    other.setIsDead();
}
//_________________________________________________________________________
void MageObject::move(const sf::Time &deltaTime, const sf::Event &event)
{
	getDir(event);
	updateAnimation();
	setPrevPosition(getPosition());
	setMove(getDirFromKey() * mageSpeed * deltaTime.asSeconds());
}
