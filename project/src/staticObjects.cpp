#include "staticObjects.hpp"

// wall class
void WallObject::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}

// crown class
void CrownObject::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}
void CrownObject::updateSpriteRect()
{
	setSpriteRect(sf::IntRect(m_col * 72, 0, 65, 50));
	m_col > 3 ? m_col = 0 : m_col++;
}

// class fire
void FireObject::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}

// class gate
void GateObject::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}

// class key
void KeyObject::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}
void KeyObject::updateSpriteRect()
{
	setSpriteRect(sf::IntRect(m_col * 60, 0, 50, 60));
	m_col > 11 ? m_col = 0 : m_col++;
}
// class monster
void MonsterObject::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}

// class teleport
void TeleporterObject::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}
void TeleporterObject::updateSpriteRect()
{
	setSpriteRect(sf::IntRect(m_col * 48, 0, 46, 60));
	m_col > 6 ? m_col = 0 : m_col++;
}

// class gift
void GiftObject::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}