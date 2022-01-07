#pragma once 

#include <SFML/Graphics.hpp>
#include "movingObjects.hpp"
#include "macros.hpp"

class FireObject;

//_______________________________
class MageObject : public MovingObjects
{
public:
	MageObject(const sf::Vector2f& location, const char key)
		: MovingObjects(location, key) {}
	~MageObject() {}
	void collide(FireObject&)override;
	void collide(TeleporterObject&)override{}

};