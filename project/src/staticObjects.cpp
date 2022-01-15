#include "staticObjects.hpp"

void StaticObjects::updateSpriteRect(const int size, const float rectLeft, const float width, const float height)
{
	setSpriteRect(sf::IntRect(m_col * rectLeft, 0, width, height));
	m_col >= size ? m_col = 0 : m_col++;
}