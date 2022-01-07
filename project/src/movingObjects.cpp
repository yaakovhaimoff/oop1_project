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
//_________________________________________________________________________
void MovingObjects::move(const sf::Time &deltaTime, const sf::Event &event)
{
	getDir(event);
	updateAnimation();
	m_prev_location = getPosition();
	setMove(dirFromKey() * 170.f * deltaTime.asSeconds());
}
//____________________________________
void MovingObjects::updateAnimation()
{
	if (m_keyDir != m_row)
		setSpriteRect(sf::IntRect(0, m_row * 32, 32, 29));
	updateCol();
}
//_______________________________________________________
void MovingObjects::getDir(const sf::Event &event)
{
	switch (event.key.code)
	{
	case sf::Keyboard::Down:
		m_row = 0;
		break;
	case sf::Keyboard::Left:
		m_row = 1;
		break;
	case sf::Keyboard::Right:
		m_row = 2;
		break;
	case sf::Keyboard::Up:
		m_row = 3;
		break;
	}
}
//_____________________________
void MovingObjects::updateCol()
{
	setSpriteRect(sf::IntRect(32 * m_col, m_row * 32, 32, 29));
	m_col > 2 ? m_col = 0 : m_col++;
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
void MovingObjects::collide(TeleporterObject &other) { setSprite(other.getConnectedTeleportLoc()); }
void MovingObjects::collide(GiftObject &other) { other.setIsDead(); }
