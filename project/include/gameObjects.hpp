#pragma once

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <vector>
#include <string>

class GameObjects
{
public:
	GameObjects(std::string);
	void handleCollision();

private:
	char m_key;
	sf::Sprite m_sprite;
};
