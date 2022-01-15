#include "dwarf.hpp"
#include "staticObjects.hpp"

//_______
namespace
{
	sf::Vector2f dirToVector(DwarfObject::Direction dir)
	{
		switch (dir)
		{
		case DwarfObject::Direction::Right:
			return {1, 0};
		case DwarfObject::Direction::Left:
			return {-1, 0};
		case DwarfObject::Direction::Up:
			return {0, -1};
		case DwarfObject::Direction::Down:
			return {0, 1};
		}
		return {0, 1};
	}
}
//______________________________________________________________________
void DwarfObject::move(const sf::Time &deltaTime, const sf::Event &event)
{
	setPrevPosition(getPosition());
	updateAnimation();
	setMove(dirToVector(m_dir) * dwarfSpeed * deltaTime.asSeconds());
	m_keyDir = m_row;
}
//______________________________
void DwarfObject::setDirection()
{
	while (m_keyDir == (m_row = rand() % 4))
		;
	newDirection(m_row);
}
//_____________________________________
void DwarfObject::newDirection(int num)
{
	switch (num)
	{
	case 0:
		m_dir = Direction::Down;
		m_row = 0;
		updateAnimation();
		break;
	case 1:
		m_dir = Direction::Left;
		m_row = 1;
		updateAnimation();
		break;
	case 2:
		m_dir = Direction::Right;
		m_row = 2;
		updateAnimation();
		break;
	case 3:
		m_dir = Direction::Up;
		m_row = 3;
		updateAnimation();
		break;
	default:
		break;
	}
}
//_________________________________
void DwarfObject::updateAnimation()
{
	m_col == 2 ? m_col = 0 : ++m_col;
	setSpriteRect(sf::IntRect(m_col * float(58.66), m_row * float(58.66), float(58.66), float(58.5)));
}