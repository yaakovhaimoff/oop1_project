#include "staticsInclude/fire.hpp"

// class fire
void FireObject::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}