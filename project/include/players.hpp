#pragma once 

#include <SFML/Graphics.hpp>
#include "MovingObjects.hpp"
#include "macros.hpp"

//_____________________________________
class KingObject : public MovingObjects
{
public:
	KingObject(sf::Vector2f location, char key)
		:MovingObjects("king.png", location, key){}

};

//______________________________________
class MageObject : public MovingObjects
{
public:
	MageObject(sf::Vector2f location, char key)
		:MovingObjects("mage.png", location, key) {}

};

//________________________________________
class WarriorObject : public MovingObjects
{
public:
	WarriorObject(sf::Vector2f location, char key)
		:MovingObjects("warrior.png", location, key) {}

};

//_______________________________________
class ThiefObject : public MovingObjects
{
public:
	ThiefObject(sf::Vector2f location, char key)
		:MovingObjects("thief.png", location, key) {}

};