#pragma once 

#include <SFML/Graphics.hpp>
#include <iostream>
#include "movingObjects.hpp"
#include "macros.hpp"

class GateObject;
class KeyObject;

//________________________________
class ThiefObject : public MovingObjects
{
public:
	ThiefObject(const sf::Vector2f& location, const char key)
		: MovingObjects(location, key), m_hasKey(0) {}
	~ThiefObject() {};
	bool thiefHasKey()const { return m_hasKey; }
	bool doesThiefhasKey() const;

	void collide(GateObject&)override;
	void collide(KeyObject&)override;

private:
	int m_hasKey;

};
