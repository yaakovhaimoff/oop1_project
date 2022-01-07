#include "gameObjects.hpp"

//___________________________________________________________________
GameObjects::GameObjects(const sf::Vector2f &location, const int key)
	: m_key(key)
{
	auto m_texture = Resources::pToRsc().getTexture(key);
	m_shape.setTexture(*m_texture);
	if (key >= King && key <= Warrior || key == Fire || key == Dwarf)
	{
		m_shape.setTextureRect(sf::IntRect(0, 0, 32, 29));
		m_shape.setScale(1.5, 1.5);
	}
	m_shape.setPosition(location);
}
//________________________________________________________
void GameObjects::drawShape(sf::RenderWindow &window) const
{
	window.draw(m_shape);
}
//__________________________________________
sf::Vector2f GameObjects::getPosition() const
{
	return m_shape.getPosition();
}
//_______________________________________________________
void GameObjects::setSprite(const sf::Vector2f &location)
{
	m_shape.setPosition(location);
}
//____________________________________________________________
void GameObjects::setMove(const sf::Vector2f &offset)
{
	m_shape.move(offset);
}
//________________________________________________________
void GameObjects::setSpriteRect(const sf::IntRect &update)
{
	m_shape.setTextureRect(update);
}
//________________________
char GameObjects::getKey()
{
	return m_key;
}
//______________________________________________________________
bool GameObjects::checkCollision(const GameObjects &other) const
{
	return m_shape.getGlobalBounds().intersects(other.m_shape.getGlobalBounds());
}