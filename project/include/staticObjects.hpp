#pragma once

#include "gameObjects.hpp"
#include "macros.hpp"
#include "king.hpp"
#include "mage.hpp"
#include "warrior.hpp"
#include "thief.hpp"


//______________________________________
class StaticObjects : public GameObjects 
{
public:
	StaticObjects(const sf::Vector2f& location, const int key)
		: GameObjects(location, key), m_isDeaed(false){}
	bool isDead() { return m_isDeaed; }
	void setIsDead() { m_isDeaed = true; }
	void setPOsition(const sf::Vector2f& location) { m_shape.setPosition(location); }
protected:
	bool m_isDeaed;
};

//_____________________________________
class WallObject : public StaticObjects
{
public:
	WallObject(const sf::Vector2f& location, const char key)
		: StaticObjects(location, key) {}

	void collide(GameObjects& other)override;
	void collide(KingObject&) override;
	void collide(MageObject&)override;
	void collide(WarriorObject&)override;
	void collide(ThiefObject&)override;
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

	void collide(GameObjects&)override;
	void collide(KingObject&) override;
	void collide(MageObject&)override;
	void collide(WarriorObject&)override;
	void collide(ThiefObject&)override;
	void collide(WallObject&)override {}
	void collide(CrownObject&)override {}
	void collide(FireObject&)override {}
	void collide(GateObject&)override {}
	void collide(KeyObject&)override {}
	void collide(MonsterObject&)override {}
	void collide(TeleporterObject&)override {}
};

//____________________________________
class FireObject : public StaticObjects
{
public:
	FireObject(const sf::Vector2f& location, const char key)
		: StaticObjects(location, key) {}

	void collide(GameObjects&)override;
	void collide(KingObject&) override;
	void collide(MageObject&)override;
	void collide(WarriorObject&)override;
	void collide(ThiefObject&)override;
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

	void collide(GameObjects&)override;
	void collide(KingObject&) override;
	void collide(MageObject&)override;
	void collide(WarriorObject&)override;
	void collide(ThiefObject&)override;
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

	void collide(GameObjects&)override;
	void collide(KingObject&) override;
	void collide(MageObject&)override;
	void collide(WarriorObject&)override;
	void collide(ThiefObject&)override;
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

	void collide(GameObjects&)override;
	void collide(KingObject&) override;
	void collide(MageObject&)override;
	void collide(WarriorObject&)override;
	void collide(ThiefObject&)override;
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

	void collide(GameObjects&)override;
	void collide(KingObject&) override;
	void collide(MageObject&)override;
	void collide(WarriorObject&)override;
	void collide(ThiefObject&)override;
	void collide(WallObject&)override {}
	void collide(CrownObject&)override {}
	void collide(FireObject&)override {}
	void collide(GateObject&)override {}
	void collide(KeyObject&)override {}
	void collide(MonsterObject&)override {}
	void collide(TeleporterObject&)override {}
};