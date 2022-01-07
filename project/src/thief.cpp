#include "thief.hpp"
#include "staticObjects.hpp"

void ThiefObject::collide(GateObject &other)
{
	if (m_hasKey > 0)
	{
		Resources::instance().playSound(OpenGate);
		other.setIsDead();
		m_hasKey = 0;
	}
	else
		setPosition();
}
void ThiefObject::collide(KeyObject &other)
{
	Resources::instance().playSound(ThiefTake);
	if (m_hasKey == 0)
		other.setIsDead();
	m_hasKey++;
}
//_______________________________________
bool ThiefObject::doesThiefhasKey() const
{
	return m_hasKey > 0;
}