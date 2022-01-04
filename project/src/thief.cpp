#include "thief.hpp"
#include "staticObjects.hpp"

void ThiefObject::collide(GateObject& other)
{
	if (m_hasKey>0)
	{
		other.setIsDead();
		m_hasKey = 0;
	}
	else
		m_shape.setPosition(this->getPrevPosition());
}
void ThiefObject::collide(KeyObject& other)
{
	if (m_hasKey==0)
		other.setIsDead();
	m_hasKey++;
}