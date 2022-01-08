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
	Board();
	void setObjectsFromBoard(std::vector<std::unique_ptr<MovingObjects>> &,
							 std::vector<std::unique_ptr<StaticObjects>> &,
							 std::vector<std::unique_ptr<TeleporterObject>> &);
	bool checkEndOfFile() const;
	void sendBoardKeysToObjects(std::vector<std::unique_ptr<MovingObjects>> &,
								std::vector<std::unique_ptr<StaticObjects>> &,
								std::vector<std::unique_ptr<TeleporterObject>> &);
	void addObjects(std::vector<std::unique_ptr<MovingObjects>> &,
					std::vector<std::unique_ptr<StaticObjects>> &,
					std::vector<std::unique_ptr<TeleporterObject>> &,
					const sf::Vector2f &, const char);
	void clearBoard();

private:
	void readBoardFile();
	void connectToTeleports(std::vector<std::unique_ptr<TeleporterObject>> &);
	std::ifstream m_boardSrcFiles;
	std::vector<std::string> m_level;
};