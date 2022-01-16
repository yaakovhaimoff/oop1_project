#include "board.hpp"
#include "data.hpp"

//____________
Board::Board()
	: m_boardSrcFiles("Board.txt")
{
	readBoardFile();
}
//_________________________
void Board::readBoardFile()
{
	for (; !(m_boardSrcFiles.eof());)
	{
		// get level time from text file
		std::string levelTime;
		std::getline(m_boardSrcFiles, levelTime);
		m_levelTime.push_back(levelTime);
		// get the board of the level
		std::vector<std::string> level;
		for (auto boardLine = std::string(); std::getline(m_boardSrcFiles, boardLine) && boardLine.compare("") != 0;)
			level.push_back(boardLine);

		m_levels.push_back(level);
	}
}
//_____________________________________________________________
void Board::sendBoardKeysToObjects(Data &data, const int level)
{
	sf::Vector2f boardCharPosition;
	for (int i = 0; i < m_levels[level].size(); i++)
	{
		for (int j = 0; j < m_levels[level][i].size(); j++)
		{
			char c = m_levels[level][i][j];
			boardCharPosition.x = (float)(SIDE_WIDTH + (60) * j);
			boardCharPosition.y = (float)(SIDE_LENGTH + (60) * i);
			data.setData(boardCharPosition, c);
		}
	}
}
//_______________________________
bool Board::checkEndOfFile() const
{
	return m_boardSrcFiles.eof();
}
//______________________
void Board::clearBoard()
{
	m_level.clear();
}