#include "gameObjects.hpp"

//________________________
GameObjects::GameObjects(std::string fileName)
{
	sf::Texture texture;
	texture.loadFromFile(fileName);
	m_sprite.setTexture(texture);

}
void GameObjects::handleCollision()
{

}