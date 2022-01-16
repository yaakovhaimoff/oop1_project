#include "staticsInclude/teleport.hpp"

// class teleport
void TeleporterObject::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}
