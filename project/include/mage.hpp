#pragma once 

#include <SFML/Graphics.hpp>
#include "MovingObjects.hpp"
#include "macros.hpp"

class KingObject;
class WarriorObject;
class ThiefObject;

//_______________________________
class MageObject : public Players
{
public:
	MageObject(const sf::Vector2f& location, const char key)
		: Players(location, key) {}
	~MageObject() {}
	void collide(GameObjects& other)override
	{
		if (this == &other) return;
		other.collide(*this);
	}
	void collide(KingObject& other) override;
	void collide(MageObject&)override {}
	void collide(WarriorObject& other)override;
	void collide(ThiefObject& other)override;
	void collide(WallObject&)override;
	void collide(CrownObject&)override;
	void collide(FireObject& /*other*/)override;
	void collide(GateObject&)override;
	void collide(KeyObject&)override {};
	void collide(MonsterObject&)override;
	void collide(TeleporterObject&)override;

};