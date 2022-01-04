#pragma once 

#include <SFML/Graphics.hpp>
#include <iostream>

#include "movingObjects.hpp"
#include "macros.hpp"

class Crown;

//_______________________________
class KingObject : public MovingObjects
{
public:
	KingObject(const sf::Vector2f& location, const int key)
		: MovingObjects(location, key){}
	~KingObject() {}

	void collide(CrownObject&)override;
};