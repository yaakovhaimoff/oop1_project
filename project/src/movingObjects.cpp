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
//_______________________________________________
sf::Vector2f MovingObjects::getDirFromKey() const { return dirFromKey(); }
//___________________________________
void MovingObjects::updateAnimation()
{
	setSpriteRect(sf::IntRect(32, m_row * 32, 32, 32));
}
//_____________________________
void MovingObjects::updateCol()
{
	while (m_col < 3)
	{
		setSpriteRect(sf::IntRect(m_col * 32, m_row * 32, 32, 32));
		++m_col;
	}
	m_col > 3 ? m_col = 0 : ++m_col;
}
//_______________________________________________________
void MovingObjects::getDir(const sf::Event &event)
{
	switch (event.key.code)
	{
	case sf::Keyboard::Down:
		m_row = 0;
		updateAnimation();
		updateCol();
		break;
	case sf::Keyboard::Left:
		m_row = 1;
		updateAnimation();
		updateCol();
		break;
	case sf::Keyboard::Right:
		m_row = 2;
		updateAnimation();
		updateCol();
		break;
	case sf::Keyboard::Up:
		m_row = 3;
		updateAnimation();
		updateCol();
		break;
	default:
		updateAnimation();
		break;
	}
}
//____________________________________________
void MovingObjects::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}
//_______________________________________
void MovingObjects::collide(WallObject &)
{
	Resources::instance().playSound(DwarfColide);
	setPosition();
}
// by default a player goes back, unless he's got a special case
// which will be over written in his class
void MovingObjects::collide(CrownObject &) { setPosition(); }
void MovingObjects::collide(FireObject &) { setPosition(); }
void MovingObjects::collide(GateObject &) { setPosition(); }
void MovingObjects::collide(KeyObject &) {}
void MovingObjects::collide(MonsterObject &) { setPosition(); }
void MovingObjects::collide(TeleporterObject &other)
{
	Resources::instance().playSound(TeleportEnter);
	setSprite(other.getConnectedTeleportLoc());
}
void MovingObjects::collide(TimeGiftObject &other)
{
	Resources::instance().playSound(GrabPresent);
	other.setIsDead();
}
void MovingObjects::collide(RemoveDwarfsObject &other)
{
	Resources::instance().playSound(GrabPresent);
	other.setIsDead();
}