#pragma once 

#include <SFML/Graphics.hpp>
#include "MovingObjects.hpp"
#include "staticObjects.hpp"
#include "macros.hpp"

//_____________________________________
class KingObject : public MovingObjects
{
public:
	KingObject(const sf::Vector2f& location, const char key)
		:MovingObjects("king.png", location, key) {}
	/*void collide(GameObjects&) override;
	void collide(KingObject&)override;
	void collide(WallObject&) override;*/

};