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
	StaticObjects(const sf::Vector2f &location, const int key)
		: GameObjects(location, key), m_isDeaed(false), m_col(0) {}
	bool isDead() { return m_isDeaed; }
	void setIsDead() { m_isDeaed = true; }
	void setPOsition(const sf::Vector2f &location) { setSprite(location); }
	void updateSpriteRect(const int, const float, const float, const float);

private:
	bool m_isDeaed;
	int m_col;
};

//_____________________________________
class WallObject : public StaticObjects
{
public:
	WallObject(const sf::Vector2f &location, const char key)
		: StaticObjects(location, key), m_col(0) {}

	void collide(GameObjects &other) override;
	void collide(KingObject &) override {}
	void collide(MageObject &) override {}
	void collide(WarriorObject &) override {}
	void collide(ThiefObject &) override {}
	void collide(DwarfObject &) override {}
	void collide(WallObject &) override {}
	void collide(CrownObject &) override {}
	void collide(FireObject &) override {}
	void collide(GateObject &) override {}
	void collide(KeyObject &) override {}
	void collide(MonsterObject &) override {}
	void collide(TeleporterObject &) override {}
	void collide(TimeGiftObject &) override {}
	void collide(RemoveDwarfsObject &) override {}

private:
	int m_col;
};

//______________________________________
class CrownObject : public StaticObjects
{
public:
	CrownObject(const sf::Vector2f &location, const char key)
		: StaticObjects(location, key), m_col(0) {}

	void collide(GameObjects &) override;
	void collide(KingObject &) override {}
	void collide(MageObject &) override {}
	void collide(WarriorObject &) override {}
	void collide(ThiefObject &) override {}
	void collide(DwarfObject &) override {}
	void collide(WallObject &) override {}
	void collide(CrownObject &) override {}
	void collide(FireObject &) override {}
	void collide(GateObject &) override {}
	void collide(KeyObject &) override {}
	void collide(MonsterObject &) override {}
	void collide(TeleporterObject &) override {}
	void collide(TimeGiftObject &) override {}
	void collide(RemoveDwarfsObject &) override {}

private:
	int m_col;
};

//____________________________________
class FireObject : public StaticObjects
{
public:
	FireObject(const sf::Vector2f &location, const char key)
		: StaticObjects(location, key), m_col(0) {}

	void collide(GameObjects &) override;
	void collide(KingObject &) override {}
	void collide(MageObject &) override {}
	void collide(WarriorObject &) override {}
	void collide(ThiefObject &) override {}
	void collide(DwarfObject &) override {}
	void collide(WallObject &) override {}
	void collide(CrownObject &) override {}
	void collide(FireObject &) override {}
	void collide(GateObject &) override {}
	void collide(KeyObject &) override {}
	void collide(MonsterObject &) override {}
	void collide(TeleporterObject &) override {}
	void collide(TimeGiftObject &) override {}
	void collide(RemoveDwarfsObject &) override {}

private:
	int m_col;
};

//_____________________________________
class GateObject : public StaticObjects
{
public:
	GateObject(const sf::Vector2f &location, const char key)
		: StaticObjects(location, key) {}

	void collide(GameObjects &) override;
	void collide(KingObject &) override {}
	void collide(MageObject &) override {}
	void collide(WarriorObject &) override {}
	void collide(ThiefObject &) override {}
	void collide(DwarfObject &) override {}
	void collide(WallObject &) override {}
	void collide(CrownObject &) override {}
	void collide(FireObject &) override {}
	void collide(GateObject &) override {}
	void collide(KeyObject &) override {}
	void collide(MonsterObject &) override {}
	void collide(TeleporterObject &) override {}
	void collide(TimeGiftObject &) override {}
	void collide(RemoveDwarfsObject &) override {}
};

//____________________________________
class KeyObject : public StaticObjects
{
public:
	KeyObject(const sf::Vector2f &location, const char key)
		: StaticObjects(location, key), m_col(0) {}

	void collide(GameObjects &) override;
	void collide(KingObject &) override {}
	void collide(MageObject &) override {}
	void collide(WarriorObject &) override {}
	void collide(ThiefObject &) override {}
	void collide(DwarfObject &) override {}
	void collide(WallObject &) override {}
	void collide(CrownObject &) override {}
	void collide(FireObject &) override {}
	void collide(GateObject &) override {}
	void collide(KeyObject &) override {}
	void collide(MonsterObject &) override {}
	void collide(TeleporterObject &) override {}
	void collide(TimeGiftObject &) override {}
	void collide(RemoveDwarfsObject &) override {}

private:
	int m_col;
};

//________________________________________
class MonsterObject : public StaticObjects
{
public:
	MonsterObject(const sf::Vector2f &location, const char key)
		: StaticObjects(location, key), m_col(0) {}

	void collide(GameObjects &) override;
	void collide(KingObject &) override {}
	void collide(MageObject &) override {}
	void collide(WarriorObject &) override {}
	void collide(ThiefObject &) override {}
	void collide(DwarfObject &) override {}
	void collide(WallObject &) override {}
	void collide(CrownObject &) override {}
	void collide(FireObject &) override {}
	void collide(GateObject &) override {}
	void collide(KeyObject &) override {}
	void collide(MonsterObject &) override {}
	void collide(TeleporterObject &) override {}
	void collide(TimeGiftObject &) override {}
	void collide(RemoveDwarfsObject &) override {}

private:
	int m_col;
};

//___________________________________________
class TeleporterObject : public StaticObjects
{
public:
	TeleporterObject(const sf::Vector2f &location, const char key, bool open)
		: StaticObjects(location, key), m_open(true), m_nextTelIndex(0), m_col(0) {}
	void setConnectedTeleport(const sf::Vector2f &location) { m_connectedTeleport = location; }
	sf::Vector2f getConnectedTeleportLoc() const { return m_connectedTeleport; }
	void setNextIndex(const int index) { m_nextTelIndex = index; }
	int getNextTelIndex() const { return m_nextTelIndex; }
	bool isTelOpen() const { return m_open; }
	void setLock(const bool lock) { m_open = lock; }

	void collide(GameObjects &) override;
	void collide(KingObject &) override {}
	void collide(MageObject &) override {}
	void collide(WarriorObject &) override {}
	void collide(ThiefObject &) override {}
	void collide(DwarfObject &) override {}
	void collide(WallObject &) override {}
	void collide(CrownObject &) override {}
	void collide(FireObject &) override {}
	void collide(GateObject &) override {}
	void collide(KeyObject &) override {}
	void collide(MonsterObject &) override {}
	void collide(TeleporterObject &) override {}
	void collide(TimeGiftObject &) override {}
	void collide(RemoveDwarfsObject &) override {}

private:
	sf::Vector2f m_connectedTeleport;
	bool m_open;
	int m_nextTelIndex;
	int m_col;
};

//___________________________________________
class TimeGiftObject : public StaticObjects
{
public:
	TimeGiftObject(const sf::Vector2f &location, const char key)
		: StaticObjects(location, key), m_col(0) {}

	void collide(GameObjects &) override;
	void collide(KingObject &) override {}
	void collide(MageObject &) override {}
	void collide(WarriorObject &) override {}
	void collide(ThiefObject &) override {}
	void collide(DwarfObject &) override {}
	void collide(WallObject &) override {}
	void collide(CrownObject &) override {}
	void collide(FireObject &) override {}
	void collide(GateObject &) override {}
	void collide(KeyObject &) override {}
	void collide(MonsterObject &) override {}
	void collide(TeleporterObject &) override {}
	void collide(TimeGiftObject &) override {}
	void collide(RemoveDwarfsObject &) override {}

private:
	int m_col;
};

//___________________________________________
class RemoveDwarfsObject : public StaticObjects
{
public:
	RemoveDwarfsObject(const sf::Vector2f &location, const char key)
		: StaticObjects(location, key), m_col(0) {}

	void collide(GameObjects &) override;
	void collide(KingObject &) override {}
	void collide(MageObject &) override {}
	void collide(WarriorObject &) override {}
	void collide(ThiefObject &) override {}
	void collide(DwarfObject &) override {}
	void collide(WallObject &) override {}
	void collide(CrownObject &) override {}
	void collide(FireObject &) override {}
	void collide(GateObject &) override {}
	void collide(KeyObject &) override {}
	void collide(MonsterObject &) override {}
	void collide(TeleporterObject &) override {}
	void collide(TimeGiftObject &) override {}
	void collide(RemoveDwarfsObject &) override {}

private:
	int m_col;
};