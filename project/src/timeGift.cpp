#include "timeGift.hpp"

// class time gift
void TimeGiftObject::collide(GameObjects &other)
{
	if (this == &other)
		return;
	other.collide(*this);
}