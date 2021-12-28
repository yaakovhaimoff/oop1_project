#pragma once 

#include "GameObjects.hpp"
#include "macros.hpp"

//___________________________________
class WallObject : public GameObjects
{
public:
	WallObject(const sf::Vector2f& location, const char key)
		:GameObjects("brickWall.png", location, key) {}

};

//_____________________________________
class CrownObject : public GameObjects
{
public:
	CrownObject(const sf::Vector2f& location, const char key)
		:GameObjects("crown.png", location, key) {}

};

//___________________________________
class FireObject : public GameObjects
{
public:
	FireObject(const sf::Vector2f& location, const char key)
		:GameObjects("fire.png", location, key) {}

};

//____________________________________
class GateObject : public GameObjects
{
public:
	GateObject(const sf::Vector2f& location, const char key)
		:GameObjects("gate.png", location, key) {}

};

//___________________________________
class KeyObject : public GameObjects
{
public:
	KeyObject(const sf::Vector2f& location, const char key)
		:GameObjects("key.png", location, key) {}

};

//______________________________________
class MonsterObject : public GameObjects
{
public:
	MonsterObject(const sf::Vector2f& location, const char key)
		:GameObjects("monster.png", location, key) {}

};

//_________________________________________
class TeleporterObject : public GameObjects
{
public:
	TeleporterObject(const sf::Vector2f& location, const char key)
		:GameObjects("teleport.png", location, key) {}

};
