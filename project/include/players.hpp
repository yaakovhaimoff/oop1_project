#pragma once 

#include <SFML/Graphics.hpp>
#include "MovingObjects.hpp"
#include "macros.hpp"

//_____________________________________
class KingObject : public MovingObjects
{
public:
	KingObject(const sf::Vector2f& location, const char key)
		:MovingObjects("king.png", location, key){}

};

//______________________________________
class MageObject : public MovingObjects
{
public:
	MageObject(const sf::Vector2f& location, const char key)
		:MovingObjects("mage.png", location, key) {}

};

//________________________________________
class WarriorObject : public MovingObjects
{
public:
	WarriorObject(const sf::Vector2f& location, const char key)
		:MovingObjects("warrior.png", location, key) {}

};

//_______________________________________
class ThiefObject : public MovingObjects
{
public:
	ThiefObject(const sf::Vector2f& location, const char key)
		:MovingObjects("thief.png", location, key) {}

};