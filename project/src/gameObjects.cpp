#include "GameObjects.hpp"

//__________________________________________________
GameObjects::GameObjects(const std::string fileName,
	const sf::Vector2f& location, const char key) : m_key(key)
{
	m_texture.loadFromFile(fileName);
	m_shape.setTexture(m_texture);
	m_shape.setPosition(location);
}
//________________________________________________________
void GameObjects::drawShape(sf::RenderWindow& window)const
{
	window.draw(m_shape);
}
//____________________________________________________
sf::FloatRect GameObjects::getShapeBoundingRect()const
{
	return m_shape.getGlobalBounds();
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