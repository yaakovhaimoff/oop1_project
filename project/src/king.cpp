#include "king.hpp"
#include "staticObjects.hpp"

void KingObject::collide(CrownObject& other) { other.setIsDead(); }
//_________________________________________________________________________
void KingObject::move(const sf::Time &deltaTime, const sf::Event &event)
{
	getDir(event);
	updateAnimation();
	setPrevPosition(getPosition());
	setMove(getDirFromKey() * kingSpeed * deltaTime.asSeconds());
}