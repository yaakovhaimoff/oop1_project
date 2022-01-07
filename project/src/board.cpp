#include "board.hpp"

//____________
Board::Board()
	: m_boardSrcFiles("Board.txt") {}
//_________________________________________________________________________________
void Board::setObjectsFromBoard(std::vector<std::unique_ptr<MovingObjects>> &players,
								std::vector<std::unique_ptr<StaticObjects>> &statics,
								std::vector<std::unique_ptr<TeleporterObject>> &teleports, const int level)
{
	readBoardFile();
	sendBoardKeysToObjects(players, statics, teleports, level);
}
//_________________________
void Board::readBoardFile()
{
	for (auto boardLine = std::string(); std::getline(m_boardSrcFiles, boardLine) && boardLine.compare("") != 0;)
		m_level.push_back(boardLine);
}
//______________________________________________________________________________________
void Board::sendBoardKeysToObjects(std::vector<std::unique_ptr<MovingObjects>> &players,
								   std::vector<std::unique_ptr<StaticObjects>> &statics,
								   std::vector<std::unique_ptr<TeleporterObject>> &teleports, const int level)
{
	sf::Vector2f boardCharPosition;
	players.resize(4);
	for (int i = 0; i < m_level.size(); i++)
	{
		for (int j = 0; j < m_level[i].size(); j++)
		{
			char c = m_level[i][j];
			boardCharPosition.x = (float)(SIDE_WIDTH + (63) * j);
			boardCharPosition.y = (float)(SIDE_LENGTH + (63) * i);
			addObjects(players, statics, teleports, boardCharPosition, c);
		}
	}
	connectToTeleports(teleports, level);
}
// returning if the file has ended
// the games will run until the end of file
// unless the player will choose to quit
//_______________________________
bool Board::checkEndOfFile() const
{
	return m_boardSrcFiles.eof();
}
//__________________________________________________________________________
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
		statics.push_back(std::make_unique<TimeGiftObject>(location, Gift));
	default:
		break;
	}
}
//________________________________________________________________________________________________________
void Board::connectToTeleports(std::vector<std::unique_ptr<TeleporterObject>> &teleports, const int level)
{
	int index = teleportsConnection[level];
	for (int i = 0; i < teleports.size(); i++)
	{
		teleports[i]->setConnectedTeleport(teleports[index % 10]->getPosition());
		teleports[i]->setNextIndex(index % 10);
		index /= 10;
	}
}
//______________________
void Board::clearBoard()
{
	m_level.clear();
}
