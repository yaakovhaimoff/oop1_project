#include "staticsInclude/key.hpp"

// class key
void KeyObject::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}