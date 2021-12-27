#pragma once

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <vector>
#include <string>

class GameObjects
{
public:
	GameObjects(std::string, sf::Vector2f);
	void handleCollision();
	void drawShape(sf::RenderWindow&)const;

protected:
	sf::Texture m_texture;
	sf::Sprite m_shape;
};
