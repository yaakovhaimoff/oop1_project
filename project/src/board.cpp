#include "board.hpp"

//________________________________________
Board::Board(const int row, const int col)
	: m_row(row), m_col(col), m_boardSrcFiles("Board.txt")
{
}
//_________________________________________________________________________________
void Board::setObjectsFromBoard(std::vector<std::unique_ptr<MovingObjects>> &players,
								std::vector<std::unique_ptr<StaticObjects>> &statics,
								std::vector<std::unique_ptr<TeleporterObject>> &teleports)
{
	std::string teleportRegularity;
	std::getline(m_boardSrcFiles, teleportRegularity);
	sf::Vector2f boardCharPosition;
	players.resize(4);
	int row = 0, col = 0;
	for (auto boardLine = std::string(); std::getline(m_boardSrcFiles, boardLine) && boardLine.compare("") != 0;)
	{
		if (boardLine.size() > col)
			col = (int)boardLine.size();
		for (int i = 0; i < boardLine.size(); i++)
		{
			char c = boardLine[i];
			boardCharPosition.x = (float)(SIDE_WIDTH + (63) * i);
			boardCharPosition.y = (float)(SIDE_LENGTH + (63) * row);
			addObjects(players, statics, teleports, boardCharPosition, c);
		}
		row++;
	}
	connectToTeleports(teleports, teleportRegularity);
	Board(row, col);
}
// returning if the file has ended
// the games will run until the end of file
// unless the player will choose to quit
//_______________________________
bool Board::checkEndOfFile() const
{
	return m_boardSrcFiles.eof();
}
//________________________________________________________________________________
void Board::addObjects(std::vector<std::unique_ptr<MovingObjects>> &players,
					   std::vector<std::unique_ptr<StaticObjects>> &statics,
					   std::vector<std::unique_ptr<TeleporterObject>> &teleports,
					   const sf::Vector2f &location, const char object)
{
	switch (object)
	{
	case KING:
		players[KING_BOARD_OBJECT] = std::make_unique<KingObject>(location, King);
		break;

	case MAGE:
		players[MAGE_BOARD_OBJECT] = std::make_unique<MageObject>(location, Mage);
		break;

	case WARRIOR:
		players[WARRIOR_BOARD_OBJECT] = std::make_unique<WarriorObject>(location, Warrior);
		break;

	case THIEF:
		players[THIEF_BOARD_OBJECT] = std::make_unique<ThiefObject>(location, Thief);
		break;

	case DWARF:
		players.push_back(std::make_unique<DwarfObject>(location, Dwarf));
		break;
		
	case WALL:
		statics.push_back(std::make_unique<WallObject>(location, Wall));
		break;

	case CROWN:
		statics.push_back(std::make_unique<CrownObject>(location, Crown));
		break;

	case FIRE:
		statics.push_back(std::make_unique<FireObject>(location, Fire));
		break;

	case GATE:
		statics.push_back(std::make_unique<GateObject>(location, Gate));
		break;

	case GATE_KEY:
		statics.push_back(std::make_unique<KeyObject>(location, Key));
		break;

	case MONSTER:
		statics.push_back(std::make_unique<MonsterObject>(location, Monster));
		break;

	case TELEPORT:
		teleports.push_back(std::make_unique<TeleporterObject>(location, Teleport, true));
		break;
		
	case GIFT:
		statics.push_back(std::make_unique<GiftObject>(location, Gift));
	default:
		break;
	}
}
//___________________________________________________________________________________
void Board::connectToTeleports(std::vector<std::unique_ptr<TeleporterObject>> &teleports,
							   std::string teleportRegularity)
{
	int index = std::stoi(teleportRegularity);
	for (int i = 0; i < teleports.size(); i++)
	{
		teleports[i]->setConnectedTeleport(teleports[index % 10]->getPosition());
		teleports[i]->setNextIndex(index % 10);
		index /= 10;
	}
}