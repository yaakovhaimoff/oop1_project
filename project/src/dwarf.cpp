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
		case DwarfObject::Direction::Stay:
			return {0, 0};
		}
		return {0, 0};
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
	while(m_keyDir == m_row)
		newDirection(rand()%4);
}
//_____________________________________
void DwarfObject::newDirection(int num)
{
	switch (num)
	{
	case 0:
		m_dir = Direction::Right;
		m_row = 0;
		break;
	case 1:
		m_dir = Direction::Left;
		m_row = 1;
		break;
	case 2:
		m_dir = Direction::Up;
		m_row = 2;
		break;
	case 3:
		m_dir = Direction::Down;
		m_row = 3;
		break;
	case 4:
		m_dir = Direction::Stay;
		break;
	}
}
//_________________________________
void DwarfObject::updateAnimation()
{
	if (m_keyDir != m_row)
		setSpriteRect(sf::IntRect(0, m_row * 32, 32, 29));
	updateCol();
}
//___________________________
void DwarfObject::updateCol()
{
	setSpriteRect(sf::IntRect(32 * m_col, m_row * 32, 32, 29));
	m_col > 2 ? m_col = 0 : m_col++;
}