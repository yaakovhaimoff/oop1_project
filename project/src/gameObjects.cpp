#include "gameObjects.hpp"

//___________________________________________________________________
GameObjects::GameObjects(const sf::Vector2f &location, const int key)
{
	m_shape.setTexture(Resources::instance().getTexture(key));
	if (key >= King && key <= Thief|| key == Dwarf)
		m_shape.setTextureRect(sf::IntRect(float(58.66), 0, float(58.66), float(58.5)));

	m_shape.setPosition(location);
}
//_________________________________________________________
void GameObjects::drawShape(sf::RenderWindow &window) const
{
	window.draw(m_shape);
}
//___________________________________________
sf::Vector2f GameObjects::getPosition() const
{
	return m_shape.getPosition();
}
//_______________________________________________________
void GameObjects::setSprite(const sf::Vector2f &location)
{
	m_shape.setPosition(location);
}
//___________________________________________________
void GameObjects::setMove(const sf::Vector2f &offset)
{
	m_shape.move(offset);
}
//________________________________________________________
void GameObjects::setSpriteRect(const sf::IntRect &update)
{
	m_shape.setTextureRect(update);
}
//______________________________________________________________
bool GameObjects::checkCollision(const GameObjects &other) const
{
	return m_shape.getGlobalBounds().intersects(other.m_shape.getGlobalBounds());
}