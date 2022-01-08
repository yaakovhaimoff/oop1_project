#include "thief.hpp"
#include "staticObjects.hpp"

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
//_________________________________________________________________________
void ThiefObject::move(const sf::Time &deltaTime, const sf::Event &event)
{
	getDir(event);
	updateAnimation();
	setPrevPosition(getPosition());
	setMove(getDirFromKey() * thiefSpeed * deltaTime.asSeconds());
}