#include "movingInclude/thief.hpp"
#include "staticsInclude/gate.hpp"
#include "staticsInclude/key.hpp"

//_________________________________________
void ThiefObject::collide(GateObject &other)
{
	if (m_hasKey)
	{
		Resources::instance().playSound(OpenGate);
		other.setIsDead();
		m_hasKey = false;
	}
	else
		setPosition();
}
//_________________________________________
void ThiefObject::collide(KeyObject &other)
{
	Resources::instance().playSound(ThiefTake);
	if (!m_hasKey)
	{
		other.setIsDead();
		m_hasKey =true;
	}
}
//_______________________________________
bool ThiefObject::doesThiefhasKey() const
{
	return m_hasKey;
}
//_______________________________________________________________________
void ThiefObject::move(const sf::Time &deltaTime, const sf::Event &event)
{
	getDir(event);
	setPrevPosition(getPosition());
	setMove(getDirFromKey() * thiefSpeed * deltaTime.asSeconds());
}