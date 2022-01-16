#pragma once 

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "macros.hpp"

class MonsterObject;

//__________________________________
class WarriorObject : public Player
{
public:
	WarriorObject(const sf::Vector2f& location, const char key)
		: Player(location, key) {}
	~WarriorObject() {};
	void move(const sf::Time&, const sf::Event&) override;
	void collide(MonsterObject&) override;

};
