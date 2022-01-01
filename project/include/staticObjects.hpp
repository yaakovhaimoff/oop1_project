#pragma once 

#include "GameObjects.hpp"
#include "king.hpp"
#include "mage.hpp"
#include "warrior.hpp"
#include "thief.hpp"
#include "macros.hpp"

//______________________________________
class StaticObjects : public GameObjects 
{
public:
	StaticObjects(const sf::Vector2f& location, const char key)
		: GameObjects(location, key) {}
};


//_____________________________________
class WallObject : public StaticObjects
{
public:
	WallObject(const sf::Vector2f& location, const char key)
		: StaticObjects(location, key) {}
	void collide(GameObjects& other)override
	{
		if (this == &other)
			return;
		other.collide(*this);
	}
	void collide(KingObject& other) override { other.collide(*this); }
	void collide(MageObject& other)override { other.collide(*this); }
	void collide(WarriorObject& other)override { other.collide(*this); }
	void collide(ThiefObject& other)override { other.collide(*this); }
	void collide(WallObject&)override {};
	void collide(CrownObject&)override {};
	void collide(FireObject&)override {};
	void collide(GateObject&)override {};
	void collide(KeyObject&)override {};
	void collide(MonsterObject&)override {};
	void collide(TeleporterObject&)override {};
};

//______________________________________
class CrownObject : public StaticObjects
{
public:
	CrownObject(const sf::Vector2f& location, const char key)
		: StaticObjects(location, key) {}
	void collide(GameObjects& other)override
	{
		if (this == &other)
			return;
		other.collide(*this);
	}
	void collide(KingObject& other) override { other.collide(*this); }
	void collide(MageObject& other)override { other.collide(*this); }
	void collide(WarriorObject& other)override { other.collide(*this); }
	void collide(ThiefObject& other)override { other.collide(*this); }
	void collide(WallObject&)override{}
	void collide(CrownObject&)override{}
	void collide(FireObject&)override{}
	void collide(GateObject&)override{}
	void collide(KeyObject&)override{}
	void collide(MonsterObject&)override{}
	void collide(TeleporterObject&)override{}
};

//____________________________________
class FireObject : public StaticObjects
{
public:
	FireObject(const sf::Vector2f& location, const char key)
		: StaticObjects(location, key) {}
	void collide(GameObjects& other)override
	{
		if (this == &other)
			return;
		other.collide(*this);
	}
	void collide(KingObject& other) override { other.collide(*this); }
	void collide(MageObject& other)override { other.collide(*this); }
	void collide(WarriorObject& other)override { other.collide(*this); }
	void collide(ThiefObject& other)override { other.collide(*this); }
	void collide(WallObject&)override {}
	void collide(CrownObject&)override {}
	void collide(FireObject&)override {}
	void collide(GateObject&)override {}
	void collide(KeyObject&)override {}
	void collide(MonsterObject&)override {}
	void collide(TeleporterObject&)override {}
};

//_____________________________________
class GateObject : public StaticObjects
{
public:
	GateObject(const sf::Vector2f& location, const char key)
		: StaticObjects(location, key) {}
	void collide(GameObjects& other)override
	{
		if (this == &other)
			return;
		other.collide(*this);
	}
	void collide(KingObject& other) override { other.collide(*this); }
	void collide(MageObject& other)override { other.collide(*this); }
	void collide(WarriorObject& other)override { other.collide(*this); }
	void collide(ThiefObject& other)override { other.collide(*this); }
	void collide(WallObject&)override {}
	void collide(CrownObject&)override {}
	void collide(FireObject&)override {}
	void collide(GateObject&)override {}
	void collide(KeyObject&)override {}
	void collide(MonsterObject&)override {}
	void collide(TeleporterObject&)override {}
};

//____________________________________
class KeyObject : public StaticObjects
{
public:
	KeyObject(const sf::Vector2f& location, const char key)
		: StaticObjects(location, key) {}
	void collide(GameObjects& other)override
	{
		if (this == &other)
			return;
		other.collide(*this);
	}
	void collide(KingObject& other) override { other.collide(*this); }
	void collide(MageObject& other)override { other.collide(*this); }
	void collide(WarriorObject& other)override { other.collide(*this); }
	void collide(ThiefObject& other)override { other.collide(*this); }
	void collide(WallObject&)override {}
	void collide(CrownObject&)override {}
	void collide(FireObject&)override {}
	void collide(GateObject&)override {}
	void collide(KeyObject&)override {}
	void collide(MonsterObject&)override {}
	void collide(TeleporterObject&)override {}
};

//________________________________________
class MonsterObject : public StaticObjects
{
public:
	MonsterObject(const sf::Vector2f& location, const char key)
		: StaticObjects(location, key) {}
	void collide(GameObjects& other)override
	{
		if (this == &other)
			return;
		other.collide(*this);
	}
	void collide(KingObject& other) override { other.collide(*this); }
	void collide(MageObject& other)override { other.collide(*this); }
	void collide(WarriorObject& other)override { other.collide(*this); }
	void collide(ThiefObject& other)override { other.collide(*this); }
	void collide(WallObject&)override {}
	void collide(CrownObject&)override {}
	void collide(FireObject&)override {}
	void collide(GateObject&)override {}
	void collide(KeyObject&)override {}
	void collide(MonsterObject&)override {}
	void collide(TeleporterObject&)override {}
};

//___________________________________________
class TeleporterObject : public StaticObjects
{
public:
	TeleporterObject(const sf::Vector2f& location, const char key)
		: StaticObjects(location, key) {}
	void collide(GameObjects& other)override
	{
		if (this == &other)
			return;
		other.collide(*this);
	}
	void collide(KingObject& other) override { other.collide(*this); }
	void collide(MageObject& other)override { other.collide(*this); }
	void collide(WarriorObject& other)override { other.collide(*this); }
	void collide(ThiefObject& other)override { other.collide(*this); }
	void collide(WallObject&)override {}
	void collide(CrownObject&)override {}
	void collide(FireObject&)override {}
	void collide(GateObject&)override {}
	void collide(KeyObject&)override {}
	void collide(MonsterObject&)override {}
	void collide(TeleporterObject&)override {}
};
