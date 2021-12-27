#pragma once

#include <stdio.h>
#include <string>
#include "GameObjects.hpp"

class MovingObjects : public GameObjects
{
public:
	MovingObjects(std::string fileName) : GameObjects(fileName) {}

};
