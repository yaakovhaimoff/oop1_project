#include "mage.hpp"
#include "staticObjects.hpp"

void MageObject::collide(FireObject& other)
{
    Resources::instance().playSound(MageFire);
    other.setIsDead();
}
