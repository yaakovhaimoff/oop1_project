#pragma once

#include "staticObjects.hpp"

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