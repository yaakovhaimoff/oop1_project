#include "staticObjects.hpp"

void StaticObjects::updateSpriteRect(const int size, const float rectLeft, const float width, const float height)
{
	setSpriteRect(sf::IntRect(m_col * rectLeft, 0, width, height));
	m_col >= size ? m_col = 0 : m_col++;
}

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

// class time gift
void TimeGiftObject::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}

// class remove dwarfs gift
void RemoveDwarfsObject::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}