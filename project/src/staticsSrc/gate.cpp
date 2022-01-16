#include "staticsInclude/gate.hpp"

// class gate
void GateObject::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}