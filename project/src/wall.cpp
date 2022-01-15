#include "wall.hpp"

// wall class
void WallObject::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}