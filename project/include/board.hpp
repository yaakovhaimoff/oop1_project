#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <memory>

#include "macros.hpp"
#include "movingObjects.hpp"
#include "staticObjects.hpp"
#include "dwarf.hpp"

class Board
{
public:
	Board(const int row = 10, const int col = 10);
	void setObjectsFromBoard(std::vector<std::unique_ptr<MovingObjects>> &,
							 std::vector<std::unique_ptr<StaticObjects>> &,
							 std::vector<std::unique_ptr<TeleporterObject>> &);
	bool checkEndOfFile() const;
	void addMovingObjects(std::vector<std::unique_ptr<MovingObjects>> &,
						  const sf::Vector2f &, const char);
	void addStaticObjects(std::vector<std::unique_ptr<StaticObjects>> &,
						  std::vector<std::unique_ptr<TeleporterObject>> &,
						  const sf::Vector2f &, const char);
	void connectToTeleports(std::vector<std::unique_ptr<TeleporterObject>> &, 
	std::string);

private:
	std::ifstream m_boardSrcFiles;
	int m_col;
	int m_row;
};