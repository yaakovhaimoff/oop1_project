#pragma once

#include "staticObjects.hpp"

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