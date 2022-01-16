#pragma once 

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "macros.hpp"

class FireObject;

//_______________________________
class MageObject : public Player
{
public:
	MageObject(const sf::Vector2f& location, const char key)
		: Player(location, key) {}
	~MageObject() {}
	void move(const sf::Time&, const sf::Event&) override;
	void collide(FireObject&)override;
	void collide(TeleporterObject&)override{}

};