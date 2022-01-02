#pragma once 

#include <SFML/Graphics.hpp>
#include "MovingObjects.hpp"
#include "macros.hpp"

class KingObject;
class MageObject;
class ThiefObject;

//__________________________________
class WarriorObject : public Players
{
public:
	WarriorObject(const sf::Vector2f& location, const char key)
		: Players(location, key) {}
	~WarriorObject() {};
	void collide(GameObjects& other)override
	{
		if (this == &other) return;
		other.collide(*this);
	}
	void collide(KingObject& other) override;
	void collide(MageObject& other)override;
	void collide(WarriorObject&)override {}
	void collide(ThiefObject& other)override;

	void collide(WallObject&)override;
	void collide(CrownObject&)override;
	void collide(FireObject&)override;
	void collide(GateObject&)override;
	void collide(KeyObject&)override {}
	void collide(MonsterObject&)override;
	void collide(TeleporterObject&)override;

};
