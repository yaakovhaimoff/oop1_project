#pragma once

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <vector>
#include <string>
#include "Resources.hpp"

class StaticObjects;

class KingObject;
class MageObject;
class WarriorObject;
class ThiefObject;
class DwarfObject;

class WallObject;
class CrownObject;
class FireObject;
class GateObject;
class KeyObject;
class MonsterObject;
class TeleporterObject;
class TimeGiftObject;

class GameObjects
{
public:
	GameObjects(const sf::Vector2f&, const int);
	void drawShape(sf::RenderWindow&)const;
	sf::Vector2f getPosition()const;
	void setSprite(const sf::Vector2f&);
	void setSpriteRect(const sf::IntRect&);
	void setMove(const sf::Vector2f&);
	bool checkCollision(const GameObjects&) const;

	virtual void collide(GameObjects& ) = 0;
	virtual void collide(KingObject& ) = 0;
	virtual void collide(MageObject& ) = 0;
	virtual void collide(WarriorObject& ) = 0;
	virtual void collide(ThiefObject& ) = 0;
	virtual void collide(DwarfObject &) =0;

	virtual void collide(WallObject& ) = 0;
	virtual void collide(CrownObject& ) = 0;
	virtual void collide(FireObject& ) = 0;
	virtual void collide(GateObject& ) = 0;
	virtual void collide(KeyObject& ) = 0;
	virtual void collide(MonsterObject& ) = 0;
	virtual void collide(TeleporterObject& ) = 0;
	virtual void collide(TimeGiftObject& ) = 0;

	virtual ~GameObjects() = default;

private:
	sf::Sprite m_shape;
};
