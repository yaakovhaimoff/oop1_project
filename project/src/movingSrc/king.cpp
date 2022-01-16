#include "movingInclude/king.hpp"
#include "staticsInclude/crown.hpp"

//__________________________________________
void KingObject::collide(CrownObject &other)
{
	setKingOnThrone();
	Resources::instance().playSound(LevelWin);
	sf::Clock clock;
	while (clock.getElapsedTime().asSeconds() < 1.0f)
		other.setIsDead();
}
//______________________________________________________________________
void KingObject::move(const sf::Time &deltaTime, const sf::Event &event)
{
	getDir(event);
	setPrevPosition(getPosition());
	setMove(getDirFromKey() * kingSpeed * deltaTime.asSeconds());
}