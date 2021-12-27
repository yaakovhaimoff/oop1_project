#include "players.hpp"

//______________________
KingObject::KingObject()
	: MovingObjects("king.png") {}

//______________________
MageObject::MageObject()
	: MovingObjects("mage.png") {}

//____________________________
WarriorObject::WarriorObject()
	: MovingObjects("warrior.png") {}

//________________________
ThiefObject::ThiefObject()
	: MovingObjects("thief.png") {}