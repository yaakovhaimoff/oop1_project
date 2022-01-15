#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "player.hpp"
#include "macros.hpp"

class Crown;

//______________________________
class KingObject : public Player
{
public:
	KingObject(const sf::Vector2f &location, const int key)
		: Player(location, key) {}
	~KingObject() {}
	void move(const sf::Time &, const sf::Event &) override;
	void collide(CrownObject &) override;
	bool getKingOnThrone() const { return m_kingOnThrone; }
	void setKingOnThrone() { m_kingOnThrone = true; }

private:
	bool m_kingOnThrone = false;
};