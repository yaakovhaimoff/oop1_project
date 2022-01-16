#include "movingInclude/movingObjects.hpp"
#include "staticsInclude/staticObjects.hpp"
#include "staticsInclude/teleport.hpp"
#include "staticsInclude/timeGift.hpp"
#include "staticsInclude/removeDwarfs.hpp"

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
//_____________________________
void MovingObjects::updateCol()
{
	m_col == 2 ? m_col = 0 : ++m_col;
	setSpriteRect(sf::IntRect(m_col * float(58.66), m_row * float(58.5),
							  float(58.66), float(58.5)));
}
//_______________________________________________________
void MovingObjects::getDir(const sf::Event &event)
{
	switch (event.key.code)
	{
	case sf::Keyboard::Down:
		m_row = 0;
		updateCol();
		break;
	case sf::Keyboard::Left:
		m_row = 1;
		updateCol();
		break;
	case sf::Keyboard::Right:
		m_row = 2;
		updateCol();
		break;
	case sf::Keyboard::Up:
		m_row = 3;
		updateCol();
		break;
	default:
		updateCol();
		m_col = 1;
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
	//Resources::instance().playSound(DwarfColide);
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