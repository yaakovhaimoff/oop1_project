#pragma once

#include "staticObjects.hpp"

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