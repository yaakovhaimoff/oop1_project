#pragma once 

#include <SFML/Graphics.hpp>
#include "MovingObjects.hpp"
#include "macros.hpp"

//______________________________________
class MageObject : public MovingObjects
{
public:
	MageObject(const sf::Vector2f& location, const char key)
		:MovingObjects("mage.png", location, key) {}
	/*void collide(GameObjects&) override;
	void collide(KingObject&)override;
	void collide(WallObject&) override;*/

};

//________________________________________
class WarriorObject : public MovingObjects
{
public:
	WarriorObject(const sf::Vector2f& location, const char key)
		:MovingObjects("warrior.png", location, key) {}
	/*void collide(GameObjects&) override;
	void collide(KingObject&)override;
	void collide(WallObject&) override;*/

};

//_______________________________________
class ThiefObject : public MovingObjects
{
public:
	ThiefObject(const sf::Vector2f& location, const char key)
		:MovingObjects("thief.png", location, key) {}
	/*void collide(GameObjects&) override;
	void collide(KingObject&)override;
	void collide(WallObject&) override;*/

};