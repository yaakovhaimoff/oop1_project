#include "mage.hpp"
#include "staticObjects.hpp"

void MageObject::collide(FireObject& other) { other.setIsDead(); }
void MageObject::collide(TeleporterObject&) {/*need to handle*/ }