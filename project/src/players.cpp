#include "Players.hpp"

//______________________
KingObject::KingObject()
	: MovingObjects("king.png", sf::Vector2f(60,60)) {}

//______________________
MageObject::MageObject()
	: MovingObjects("mage.png", sf::Vector2f(100, 100)) {}

//____________________________
WarriorObject::WarriorObject()
	: MovingObjects("warrior.png", sf::Vector2f(100, 100)) {}

//________________________
ThiefObject::ThiefObject()
	: MovingObjects("thief.png", sf::Vector2f(100, 100)) {}