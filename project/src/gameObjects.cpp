#include "GameObjects.hpp"

//___________________________________________________________________
GameObjects::GameObjects(const sf::Vector2f& location, const int key)
	: m_key(key)
{
	auto m_texture = Resources::pToRsc().getTexture(key);
	m_shape.setTexture(*m_texture);
	m_shape.setPosition(location);
}
//________________________________________________________
void GameObjects::drawShape(sf::RenderWindow& window)const
{
	window.draw(m_shape);
}
//__________________________________________
sf::Vector2f GameObjects::getPosition()const
{
	return m_shape.getPosition();
}
//________________________
char GameObjects::getKey()
{
	return m_key;
}
//______________________________________________________________
bool GameObjects::checkCollision(const GameObjects& other) const
{
	return m_shape.getGlobalBounds().intersects(other.m_shape.getGlobalBounds());
}