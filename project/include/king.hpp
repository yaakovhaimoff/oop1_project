#pragma once 

#include <SFML/Graphics.hpp>
#include <iostream>

#include "MovingObjects.hpp"
#include "macros.hpp"

class MageObject;
class WarriorObject;
class ThiefObject;
class Crown;
class TeleporterObject;

//_______________________________
class KingObject : public Players
{
public:
	KingObject(const sf::Vector2f& location, const int key)
		: Players(location, key), m_onCrown(false){}
	~KingObject() {}
	bool isKingOnThrone()const { return m_onCrown; }

	void collide(GameObjects&)override;
	void collide(KingObject&)override {}
	void collide(MageObject&)override;
	void collide(WarriorObject&)override;
	void collide(ThiefObject&)override;
	void collide(WallObject&)override;
	void collide(CrownObject&)override;
	void collide(FireObject&)override;
	void collide(GateObject&)override;
	void collide(KeyObject&)override;
	void collide(MonsterObject&)override;
	void collide(TeleporterObject&)override;
private:
	bool m_onCrown;

};