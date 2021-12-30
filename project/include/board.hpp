#pragma once 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <memory>

#include "macros.hpp"
#include "Players.hpp"
#include "movingObjects.hpp"
#include "staticObjects.hpp"

class Board 
{
public:
	Board(const int row = 10, const int col = 10 );
	void setObjectsFromBoard(std::vector<std::unique_ptr<MovingObjects>>&, 
							std::vector<std::unique_ptr<StaticObjects>>&);
	void addMovingObjects(std::vector<std::unique_ptr<MovingObjects>>&,
		const sf::Vector2f&, char);
	void addStaticObjects(std::vector<std::unique_ptr<StaticObjects>>&,
		const sf::Vector2f&, char);

private:
	int m_col;
	int m_row;

};