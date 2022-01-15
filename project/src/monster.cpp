#include "monster.hpp"

// class monster
void MonsterObject::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}