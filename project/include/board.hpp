#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <memory>

#include "macros.hpp"

class Data;

class Board
{
public:
	Board();
	void setObjectsFromBoard(Data&);
	bool checkEndOfFile() const;
	void sendBoardKeysToObjects(Data&);
	void clearBoard();

private:
	void readBoardFile();
	std::ifstream m_boardSrcFiles;
	std::vector<std::string> m_level;
};