#include "GameObjects.hpp"

//________________________
GameObjects::GameObjects(std::string fileName, sf::Vector2f location)
{
	sf::Texture texture;
	texture.loadFromFile(fileName);
	m_shape.setTexture(texture);
	m_shape.setPosition(location);
}
//________________________________________________________
void GameObjects::drawShape(sf::RenderWindow& window)const
{
	window.draw(m_shape);
}
void GameObjects::handleCollision()
{

}