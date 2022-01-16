#include "staticsInclude/crown.hpp"

// crown class
void CrownObject::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}