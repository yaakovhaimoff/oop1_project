#include "board.hpp"

//________________________________________
Board::Board(const int row, const int col)
	: m_row(row), m_col(col), m_boardSrcFiles("Board.txt")
{}
//_________________________________________________________________________________
void Board::setObjectsFromBoard(std::vector<std::unique_ptr<Players>>& players,
	std::vector<std::unique_ptr<StaticObjects>>& statics)
{
	sf::Vector2f boardCharPosition;
	int row = 0, col = 0, teleportAmount = 0, nextTeleportSpace;
	for (auto boardLine = std::string(); std::getline(m_boardSrcFiles, boardLine) && boardLine.compare("") != 0;)
	{
		if (boardLine.size() > col)
			col = (int)boardLine.size();
		for (int i = 0; i < boardLine.size(); i++)
		{
			char c = boardLine[i];
			boardCharPosition.x = (float)(SIDE_WIDTH + (63) * i);
			boardCharPosition.y = (float)(SIDE_LENGTH + (63) * row);
			this->addMovingObjects(players, boardCharPosition, c);
			this->addStaticObjects(statics, boardCharPosition, c, teleportAmount, nextTeleportSpace);
		}
		row++;
	}
	Board(row, col);
}
// returning if the file has ended
// the games will run until the end of file
// unless the player will choose to quit
//_______________________________
bool Board::checkEndOfFile()const
{
	return m_boardSrcFiles.eof();
}
//________________________________________________________________________________
void Board::addMovingObjects(std::vector<std::unique_ptr<Players>>& players,
	const sf::Vector2f& location, const char object)
{
	switch (object)
	{
	case KING:
		players.push_back(std::make_unique<KingObject>(location, King));
		break;

	case MAGE:
		players.push_back(std::make_unique<MageObject>(location, Mage));
		break;

	case WARRIOR:
		players.push_back(std::make_unique<WarriorObject>(location, Warrior));
		break;

	case THIEF:
		players.push_back(std::make_unique<ThiefObject>(location, Thief));
		break;

	default:
		break;
	}
}
//________________________________________________________________________________
void Board::addStaticObjects(std::vector<std::unique_ptr<StaticObjects>>& statics,
	const sf::Vector2f& location, const char object, int& teleportAmount, int& nextTeleportSpace)
{
	switch (object)
	{
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
		this->addTeleport(statics, location, teleportAmount, nextTeleportSpace);
		break;

	default:
		break;
	}
}
//__________________________________________________________________________
void Board::addTeleport(std::vector<std::unique_ptr<StaticObjects>>& statics,
	const sf::Vector2f& location, int& amountOfTelports, int& nextTeleportSpace)
{
	if (amountOfTelports % 2 == 0)
	{
		statics.push_back(std::make_unique<TeleporterObject>(location, Teleport));
		statics.push_back(std::make_unique<TeleporterObject>(location, Teleport));
		nextTeleportSpace = (int)statics.size() - 1;
	}
	else
		statics[nextTeleportSpace]->setPOsition(location);
	amountOfTelports++;
}