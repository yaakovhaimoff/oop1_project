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
void DwarfObject::moving(const sf::Time &deltaTime, const sf::Event &event, const bool newDir)
{
	setPrevPosition(getPosition());
	if (!newDir)
	{
		updateAnimation();
		updateCol();
	}
	setMove(dirToVector(m_dir) * dwarfSpeed * deltaTime.asSeconds());
	m_keyDir = m_row;
}
//______________________________
void DwarfObject::setDirection()
{
	// while (m_keyDir == m_row)
	// 	newDirection(rand() % 4);
	// updateAnimation();
	while ((m_row = rand() % 4) == m_keyDir)
		;
	newDirection(m_row);
}
//_____________________________________
void DwarfObject::newDirection(int num)
{
	switch (num)
	{
	case 0:
		m_dir = Direction::Right;
		m_row = 0;
		updateAnimation();
		updateCol();
		break;
	case 1:
		m_dir = Direction::Left;
		m_row = 1;
		updateAnimation();
		updateCol();
		break;
	case 2:
		m_dir = Direction::Up;
		m_row = 2;
		updateAnimation();
		updateCol();
		break;
	case 3:
		m_dir = Direction::Down;
		m_row = 3;
		updateAnimation();
		updateCol();
		break;
	}
}
//_________________________________
void DwarfObject::updateAnimation()
{
	setSpriteRect(sf::IntRect(32, m_row * 32, 32, 32));
}
//___________________________
void DwarfObject::updateCol()
{
	while (m_col < 3)
	{
		setSpriteRect(sf::IntRect(m_col * 32, m_row * 32, 32, 32));
		++m_col;
	}
	m_col > 3 ? m_col = 0 : ++m_col;
}