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
		return {0, 0}; // just to silence the warning about no return
					   // would be better to throw an exception but we haven't learned about it yet
	}
}
//______________________________________________________________________
void DwarfObject::move(const sf::Time& deltaTime, const sf::Event& event)
{
	setDirection(rand()%4);
	m_shape.move(dirToVector(m_dir) * 150.f * deltaTime.asSeconds());
}
//_____________________________________
void DwarfObject::setDirection(int num)
{
	switch (num)
	{
	case 0:
		m_dir = Direction::Right;
		break;
	case 1:
		m_dir = Direction::Left;
		break;
	case 2:
		m_dir = Direction::Up;
		break;
	case 3:
		m_dir = Direction::Down;
		break;
		case 4: m_dir = Direction::Stay;  break;
	}
}