#pragma once 

#include <SFML/Graphics.hpp>
#include "MovingObjects.hpp"
#include "macros.hpp"

class KingObject;
class WarriorObject;
class ThiefObject;
class FireObject;

//_______________________________
class MageObject : public Players
{
public:
	MageObject(const sf::Vector2f& location, const char key)
		: Players(location, key) {}
	~MageObject() {}
	void collide(GameObjects&)override;
	void collide(KingObject&)override;
	void collide(MageObject&)override {}
	void collide(WarriorObject&)override;
	void collide(ThiefObject&)override;
	void collide(WallObject&)override;
	void collide(CrownObject&)override;
	void collide(FireObject&)override;
	void collide(GateObject&)override;
	void collide(KeyObject&)override {};
	void collide(MonsterObject&)override;
	void collide(TeleporterObject&)override;

};