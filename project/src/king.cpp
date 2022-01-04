#include "king.hpp"
#include "staticObjects.hpp"

void KingObject::collide(CrownObject& other) { other.setIsDead(); }