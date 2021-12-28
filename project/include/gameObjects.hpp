#pragma once

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <vector>
#include <string>

class GameObjects
{
public:
	GameObjects(const std::string, const sf::Vector2f&, const char);
	void handleCollision();
	void drawShape(sf::RenderWindow&)const;
	char getKey();
	virtual void move(sf::Time){}

protected:
	sf::Texture m_texture;
	sf::Sprite m_shape;
	char m_key;
};
