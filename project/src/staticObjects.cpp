#include "staticObjects.hpp"
//#include "king.hpp"
//#include "mage.hpp"
//#include "warrior.hpp"
//#include "thief.hpp"

// wall class
void WallObject::collide(KingObject& other) { other.collide(*this); }
void WallObject::collide(MageObject& other) { other.collide(*this); }
void WallObject::collide(WarriorObject& other) { other.collide(*this); }
void WallObject::collide(ThiefObject& other) { other.collide(*this); }

// crown class
void CrownObject::collide(KingObject& other) { other.collide(*this); }
void CrownObject::collide(MageObject& other) { other.collide(*this); }
void CrownObject::collide(WarriorObject& other) { other.collide(*this); }
void CrownObject::collide(ThiefObject& other) { other.collide(*this); }


// class fire
void FireObject::collide(KingObject& other) { other.collide(*this); }
void FireObject::collide(MageObject& other) { other.collide(*this); }
void FireObject::collide(WarriorObject& other) { other.collide(*this); }
void FireObject::collide(ThiefObject& other) { other.collide(*this); }


// class gate
void GateObject::collide(KingObject& other) { other.collide(*this); }
void GateObject::collide(MageObject& other) { other.collide(*this); }
void GateObject::collide(WarriorObject& other) { other.collide(*this); }
void GateObject::collide(ThiefObject& other) { other.collide(*this); }


// class key
void KeyObject::collide(KingObject& other) { other.collide(*this); }
void KeyObject::collide(MageObject& other) { other.collide(*this); }
void KeyObject::collide(WarriorObject& other) { other.collide(*this); }
void KeyObject::collide(ThiefObject& other) { other.collide(*this); }

// class monster
void MonsterObject::collide(KingObject& other) { other.collide(*this); }
void MonsterObject::collide(MageObject& other) { other.collide(*this); }
void MonsterObject::collide(WarriorObject& other) { other.collide(*this); }
void MonsterObject::collide(ThiefObject& other) { other.collide(*this); }

// class teleport
void TeleporterObject::collide(KingObject& other) { other.collide(*this); }
void TeleporterObject::collide(MageObject& other) { other.collide(*this); }
void TeleporterObject::collide(WarriorObject& other) { other.collide(*this); }
void TeleporterObject::collide(ThiefObject& other) { other.collide(*this); }
