#pragma once 

#include <SFML/Graphics.hpp>
#include <iostream>
#include "movingObjects.hpp"
#include "macros.hpp"

class KingObject;
class MageObject;
class WarriorObject;
class GateObject;
class KeyObject;
class TeleporterObject;

//________________________________
class ThiefObject : public Players
{
public:
	ThiefObject(const sf::Vector2f& location, const char key)
		: Players(location, key), m_hasKey(0) {}
	~ThiefObject() {};
	bool thiefHasKey()const { return m_hasKey; }
	void collide(GameObjects&)override;
	void collide(KingObject&)override;
	void collide(MageObject&)override;
	void collide(WarriorObject&)override;
	void collide(ThiefObject&)override {}
	void collide(WallObject&)override;
	void collide(CrownObject&)override;
	void collide(FireObject&)override;
	void collide(GateObject&)override;
	void collide(KeyObject&)override;
	void collide(MonsterObject&)override;
	void collide(TeleporterObject&)override;

private:
	int m_hasKey;

};
