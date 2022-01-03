#pragma once 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <memory>

#include "macros.hpp"
#include "movingObjects.hpp"
#include "staticObjects.hpp"

class Board 
{
public:
	Board(const int row = 10, const int col = 10 );
	void setObjectsFromBoard(std::vector<std::unique_ptr<Players>>&,
							std::vector<std::unique_ptr<StaticObjects>>&);
	bool checkEndOfFile()const;
	void addMovingObjects(std::vector<std::unique_ptr<Players>>&,
		const sf::Vector2f&, const char);
	void addStaticObjects(std::vector<std::unique_ptr<StaticObjects>>&,
		const sf::Vector2f&, const char, int&, int&);
	void addTeleport(std::vector<std::unique_ptr<StaticObjects>>&,
		const sf::Vector2f&, int&, int&);

private:
	std::ifstream m_boardSrcFiles;
	int m_col;
	int m_row;

};