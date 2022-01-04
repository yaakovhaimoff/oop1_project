#pragma once 

#include <SFML/Graphics.hpp>
#include "movingObjects.hpp"
#include "macros.hpp"

class MonsterObject;

//__________________________________
class WarriorObject : public MovingObjects
{
public:
	WarriorObject(const sf::Vector2f& location, const char key)
		: MovingObjects(location, key) {}
	~WarriorObject() {};
	void collide(MonsterObject&) override;

};
