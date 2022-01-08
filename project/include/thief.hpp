#pragma once 

#include <SFML/Graphics.hpp>
#include <iostream>
#include "movingObjects.hpp"
#include "macros.hpp"

class GateObject;
class KeyObject;

//______________________________________
class ThiefObject : public MovingObjects
{
public:
	ThiefObject(const sf::Vector2f& location, const char key)
		: MovingObjects(location, key), m_hasKey(false) {}
	~ThiefObject() {};
	bool thiefHasKey()const { return m_hasKey; }
	bool doesThiefhasKey() const;
	void move(const sf::Time&, const sf::Event&) override;
	void collide(GateObject&)override;
	void collide(KeyObject&)override;

private:
	bool m_hasKey;
};
