#include "board.hpp"
#include "data.hpp"

//____________
Board::Board()
	: m_boardSrcFiles("Board.txt"){}
//_________________________________________
void Board::setObjectsFromBoard(Data &data)
{
	readBoardFile();
	sendBoardKeysToObjects(data);
}
//_________________________
void Board::readBoardFile()
{
	for (auto boardLine = std::string(); std::getline(m_boardSrcFiles, boardLine) && boardLine.compare("") != 0;)
		m_level.push_back(boardLine);
}
//____________________________________________
void Board::sendBoardKeysToObjects(Data &data)
{
	sf::Vector2f boardCharPosition;
	for (int i = 0; i < m_level.size(); i++)
	{
		for (int j = 0; j < m_level[i].size(); j++)
		{
			char c = m_level[i][j];
			boardCharPosition.x = (float)(SIDE_WIDTH + (63) * j);
			boardCharPosition.y = (float)(SIDE_LENGTH + (63) * i);
			data.setData(boardCharPosition, c);
		}
	}
}
// returning if the file has ended
// the games will run until the end of file
// unless the player will choose to quit
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
