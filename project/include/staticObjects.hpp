#pragma once 

#include "GameObjects.hpp"
#include "macros.hpp"

//______________________________________
class StaticObjects : public GameObjects 
{
public:
	StaticObjects(const std::string fileName, const sf::Vector2f& location, const char key)
		: GameObjects(fileName, location, key) {}
};


//_____________________________________
class WallObject : public StaticObjects
{
public:
	WallObject(const sf::Vector2f& location, const char key)
		: StaticObjects("brickWall.png", location, key) {}
};

//______________________________________
class CrownObject : public StaticObjects
{
public:
	CrownObject(const sf::Vector2f& location, const char key)
		: StaticObjects("crown.png", location, key) {}
};

//____________________________________
class FireObject : public StaticObjects
{
public:
	FireObject(const sf::Vector2f& location, const char key)
		: StaticObjects("fire.png", location, key) {}
};

//_____________________________________
class GateObject : public StaticObjects
{
public:
	GateObject(const sf::Vector2f& location, const char key)
		: StaticObjects("gate.png", location, key) {}
};

//____________________________________
class KeyObject : public StaticObjects
{
public:
	KeyObject(const sf::Vector2f& location, const char key)
		: StaticObjects("key.png", location, key) {}
};

//________________________________________
class MonsterObject : public StaticObjects
{
public:
	MonsterObject(const sf::Vector2f& location, const char key)
		: StaticObjects("monster.png", location, key) {}
};

//___________________________________________
class TeleporterObject : public StaticObjects
{
public:
	TeleporterObject(const sf::Vector2f& location, const char key)
		: StaticObjects("teleport.png", location, key) {}
};
