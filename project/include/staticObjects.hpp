#pragma once 

#include "GameObjects.hpp"
#include "macros.hpp"

//___________________________________
class WallObject : public GameObjects
{
public:
	WallObject(sf::Vector2f location, char key) 
		:GameObjects("brickWall.png", location, key) {}

};

//_____________________________________
class CrownObject : public GameObjects
{
public:
	CrownObject(sf::Vector2f location, char key)
		:GameObjects("crown.png", location, key) {}

};

//___________________________________
class FireObject : public GameObjects
{
public:
	FireObject(sf::Vector2f location, char key)
		:GameObjects("fire.png", location, key) {}

};

//____________________________________
class GateObject : public GameObjects
{
public:
	GateObject(sf::Vector2f location, char key)
		:GameObjects("gate.png", location, key) {}

};

//___________________________________
class KeyObject : public GameObjects
{
public:
	KeyObject(sf::Vector2f location, char key)
		:GameObjects("key.png", location, key) {}

};

//______________________________________
class MonsterObject : public GameObjects
{
public:
	MonsterObject(sf::Vector2f location, char key)
		:GameObjects("monster.png", location, key) {}

};

//_________________________________________
class TeleporterObject : public GameObjects
{
public:
	TeleporterObject(sf::Vector2f location, char key)
		:GameObjects("teleport.png", location, key) {}

};
