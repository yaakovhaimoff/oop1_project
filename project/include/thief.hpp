#pragma once 

#include <SFML/Graphics.hpp>
#include <iostream>

#include "MovingObjects.hpp"
#include "macros.hpp"

class KingObject;
class MageObject;
class WarriorObject;

//________________________________
class ThiefObject : public Players
{
public:
	ThiefObject(const sf::Vector2f& location, const char key)
		: Players(location, key), m_hasKey(false) {}
	~ThiefObject() {};
	bool thiefHasKey()const { return m_hasKey; }
	void collide(GameObjects& other)override
	{
		if (this == &other) return;
		other.collide(*this);
	}
	void collide(KingObject& other)override;
	void collide(MageObject& other)override;
	void collide(WarriorObject& other)override;
	void collide(ThiefObject&)override {}
	void collide(WallObject&)override;
	void collide(CrownObject&)override;
	void collide(FireObject&)override;
	void collide(GateObject&)override;
	void collide(KeyObject&)override;
	void collide(MonsterObject&)override;
	void collide(TeleporterObject&)override;

private:
	bool m_hasKey;

};
