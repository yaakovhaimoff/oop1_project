#include "board.hpp"

//____________________________
Board::Board(int row, int col)
	: m_row(row), m_col(col){}
//_________________________________
void Board::setObjectsFromBoard(std::vector<std::unique_ptr<GameObjects>>& players)
{
	std::ifstream savedFileBoard;
	savedFileBoard.open("Board.txt");
	if (!savedFileBoard.is_open())
		std::cout << "No baord saved previously\n\n";
	sf::Vector2f boardCharPosition;
	int row = 0, col = 0;
	bool isFile = false;
	while (savedFileBoard)
	{
		isFile = true;
		std::string boardLine;
		std::getline(savedFileBoard, boardLine);
		if (boardLine.size() > col)
			col = (int)boardLine.size();
		for (int i = 0; i < boardLine.size(); i++)
		{
			char c = boardLine[i];
			boardCharPosition.x = (float)(SIDE_WIDTH + (63) * i);
			boardCharPosition.y = (float)(SIDE_LENGTH + (63) * row);
			this->addObjectsFromBoard(players, boardCharPosition, c);
		}
		row++;
	}
	Board(row, col);
}
//__________________________________________________________________________________
void Board::addObjectsFromBoard(std::vector<std::unique_ptr<GameObjects>>& players,
	const sf::Vector2f& location, char object)
{
	switch (object)
	{
	case KING:
		players.push_back(std::make_unique<KingObject>(location, KING));
		break;

	case MAGE:
		players.push_back(std::make_unique<MageObject>(location, MAGE));
		break;

	case WARRIOR:
		players.push_back(std::make_unique<WarriorObject>(location, WARRIOR));
		break;

	case THIEF:
		players.push_back(std::make_unique<ThiefObject>(location, THIEF));
		break;

	case WALL:
		players.push_back(std::make_unique<WallObject>(location, WALL));
		break;

	case CROWN:
		players.push_back(std::make_unique<CrownObject>(location, CROWN));
		break;

	case FIRE:
		players.push_back(std::make_unique<FireObject>(location, FIRE));
		break;

	case GATE:
		players.push_back(std::make_unique<GateObject>(location, GATE));
		break;

	case GATE_KEY:
		players.push_back(std::make_unique<KeyObject>(location, GATE_KEY));
		break;

	case MONSTER:
		players.push_back(std::make_unique<MonsterObject>(location, MONSTER));
		break;

	case TELEPORT:
		players.push_back(std::make_unique<TeleporterObject>(location, TELEPORT));
		break;

	default:
		break;
	}
}
