#include "MovingObjects.hpp"

//_______
namespace
{
	sf::Vector2f dirFromKey()
	{
		static const
			std::initializer_list<std::pair<sf::Keyboard::Key, sf::Vector2f>>
			keyToVectorMapping =
		{
			{ sf::Keyboard::Right, { 1, 0 } },
			{ sf::Keyboard::Left , { -1, 0 } },
			{ sf::Keyboard::Up   , { 0, -1 } },
			{ sf::Keyboard::Down , { 0, 1 } },
		};
		for (const auto& pair : keyToVectorMapping)
		{
			if (sf::Keyboard::isKeyPressed(pair.first))
			{
				return pair.second;
			}
		}
		return { 0, 0 };
	}
}
//__________________________________________
void MovingObjects::move(sf::Time deltaTime)
{
	m_shape.move(dirFromKey() * 170.f * deltaTime.asSeconds());
}
//_____________________________________________________________
sf::Vector2f MovingObjects::getNextPosition(sf::Time deltaTime)
{
	return m_shape.getPosition() + this->direction(deltaTime);
}
//_______________________________________________________
sf::Vector2f MovingObjects::direction(sf::Time deltaTime)
{
	return (dirFromKey() * 170.f * deltaTime.asSeconds());
}