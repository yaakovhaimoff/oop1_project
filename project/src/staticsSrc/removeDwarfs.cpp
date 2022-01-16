#include "staticsInclude/removeDwarfs.hpp"

// class remove dwarfs gift
void RemoveDwarfsObject::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}