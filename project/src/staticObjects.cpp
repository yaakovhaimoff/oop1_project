#include "staticObjects.hpp"

// wall class
void WallObject::collide(GameObjects& other)
{
	if (this == &other)
		return;
	other.collide(*this);
}
void WallObject::collide(KingObject& other) { other.collide(*this); }
void WallObject::collide(MageObject& other) { other.collide(*this); }
void WallObject::collide(WarriorObject& other) { other.collide(*this); }
void WallObject::collide(ThiefObject& other) { other.collide(*this); }

// crown class
void CrownObject::collide(GameObjects& other)
{
	if (this == &other)
		return;
	other.collide(*this);
}
void CrownObject::collide(KingObject& other) { other.collide(*this); }
void CrownObject::collide(MageObject& other) { other.collide(*this); }
void CrownObject::collide(WarriorObject& other) { other.collide(*this); }
void CrownObject::collide(ThiefObject& other) { other.collide(*this); }


// class fire
void FireObject::collide(GameObjects& other)
{
	if (this == &other)
		return;
	other.collide(*this);
}
void FireObject::collide(KingObject& other) { other.collide(*this); }
void FireObject::collide(MageObject& other) { other.collide(*this); }
void FireObject::collide(WarriorObject& other) { other.collide(*this); }
void FireObject::collide(ThiefObject& other) { other.collide(*this); }


// class gate
void GateObject::collide(GameObjects& other)
{
	if (this == &other)
		return;
	other.collide(*this);
}
void GateObject::collide(KingObject& other) { other.collide(*this); }
void GateObject::collide(MageObject& other) { other.collide(*this); }
void GateObject::collide(WarriorObject& other) { other.collide(*this); }
void GateObject::collide(ThiefObject& other) { other.collide(*this); }


// class key
void KeyObject::collide(GameObjects& other)
{
	if (this == &other)
		return;
	other.collide(*this);
}
void KeyObject::collide(KingObject& other) { other.collide(*this); }
void KeyObject::collide(MageObject& other) { other.collide(*this); }
void KeyObject::collide(WarriorObject& other) { other.collide(*this); }
void KeyObject::collide(ThiefObject& other) { other.collide(*this); }

// class monster
void MonsterObject::collide(GameObjects& other)
{
	if (this == &other)
		return;
	other.collide(*this);
}
void MonsterObject::collide(KingObject& other) { other.collide(*this); }
void MonsterObject::collide(MageObject& other) { other.collide(*this); }
void MonsterObject::collide(WarriorObject& other) { other.collide(*this); }
void MonsterObject::collide(ThiefObject& other) { other.collide(*this); }

// class teleport
void TeleporterObject::collide(GameObjects& other)
{
	if (this == &other)
		return;
	other.collide(*this);
}
void TeleporterObject::collide(KingObject& other) { other.collide(*this); }
void TeleporterObject::collide(MageObject& other) { other.collide(*this); }
void TeleporterObject::collide(WarriorObject& other) { other.collide(*this); }
void TeleporterObject::collide(ThiefObject& other) { other.collide(*this); }
