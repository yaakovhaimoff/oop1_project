#include "movingObjects.hpp"
#include "staticObjects.hpp"

//_______
namespace
{
	sf::Vector2f dirFromKey()
	{
		static const std::initializer_list<std::pair<sf::Keyboard::Key, sf::Vector2f>>
			keyToVectorMapping =
				{
					{sf::Keyboard::Right, {1, 0}},
					{sf::Keyboard::Left, {-1, 0}},
					{sf::Keyboard::Up, {0, -1}},
					{sf::Keyboard::Down, {0, 1}},
				};
		for (const auto &pair : keyToVectorMapping)
		{
			if (sf::Keyboard::isKeyPressed(pair.first))
			{
				return pair.second;
			}
		}
		return {0, 0};
	}
}
//__________________________________________
void MovingObjects::move(sf::Time deltaTime)
{
	m_prev_location = m_shape.getPosition();
	m_shape.move(dirFromKey() * 170.f * deltaTime.asSeconds());
}
//____________________________________________
void MovingObjects::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}
void MovingObjects::collide(WallObject &) { setPosition(); }
void MovingObjects::collide(CrownObject &) { setPosition(); }
void MovingObjects::collide(FireObject &) { setPosition(); }
void MovingObjects::collide(GateObject &) { setPosition(); }
void MovingObjects::collide(KeyObject &) {}
void MovingObjects::collide(MonsterObject &) { setPosition(); }
void MovingObjects::collide(TeleporterObject &other) { m_shape.setPosition(other.getConnectedTeleportLoc()); }

