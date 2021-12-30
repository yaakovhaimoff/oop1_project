#pragma once

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <vector>
#include <string>

class KingObject;
class WallObject;
class StaticObjects;

class GameObjects
{
public:
	GameObjects(const std::string, const sf::Vector2f&, const char);
	void drawShape(sf::RenderWindow&)const;
	sf::FloatRect getShapeBoundingRect()const;
	sf::Vector2f getPosition()const;
	char getKey();
	bool checkCollision(const GameObjects&) const;
	/*virtual void collide(GameObjects& ) = 0;
	virtual void collide(KingObject& ) = 0;
	virtual void collide(WallObject& ) = 0;*/

	virtual ~GameObjects() = default;

protected:
	sf::Texture m_texture;
	sf::Sprite m_shape;
	char m_key;
};
