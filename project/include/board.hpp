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
	void readBoardFile();
	bool checkEndOfFile() const;
	void sendBoardKeysToObjects(Data&, const int);
	void clearBoard();
	int getLevelTime(const int level)const { return std::stoi(m_levelTime[level]); }

private:
	std::ifstream m_boardSrcFiles;
	std::vector<std::string> m_level;
	std::vector<std::string> m_levelTime;
	std::vector<std::vector<std::string>> m_levels;
};