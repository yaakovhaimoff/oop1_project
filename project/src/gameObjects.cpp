#include "GameObjects.hpp"

//____________________________________________
GameObjects::GameObjects(std::string fileName,
	sf::Vector2f location)
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
//_________________________________
void GameObjects::handleCollision()
{

}