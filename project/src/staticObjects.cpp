#include "staticObjects.hpp"

// wall class
void WallObject::collide(GameObjects& other)
{
	if (this == &other)
		return;
	other.collide(*this);
}

// crown class
void CrownObject::collide(GameObjects& other)
{
	if (this == &other)
		return;
	other.collide(*this);
}

// class fire
void FireObject::collide(GameObjects& other)
{
	if (this == &other)
		return;
	other.collide(*this);
}

// class gate
void GateObject::collide(GameObjects& other)
{
	if (this == &other)
		return;
	other.collide(*this);
}

// class key
void KeyObject::collide(GameObjects& other)
{
	if (this == &other)
		return;
	other.collide(*this);
}

// class monster
void MonsterObject::collide(GameObjects& other)
{
	if (this == &other)
		return;
	other.collide(*this);
}

// class teleport
void TeleporterObject::collide(GameObjects& other)
{
	if (this == &other)
		return;
	other.collide(*this);
}