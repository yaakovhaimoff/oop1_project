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
//________________________
char GameObjects::getKey()
{
	return m_key;
}
//_________________________________
void GameObjects::handleCollision()
{

}