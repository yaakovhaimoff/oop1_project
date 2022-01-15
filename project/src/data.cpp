#include "data.hpp"
#include "Controller.hpp"

//________________________________
Data::Data(Controller &controller)
{
    m_controller = &controller;
}
//______________________________
void Data::setDataToLevelStart(const int level)
{
    m_players.resize(numOfPlayers);
    m_board.sendBoardKeysToObjects(*this, level);
    connectToTeleports();
}
//________________________________
void Data::setDataToLevelRestart(const int level)
{
    m_players.resize(numOfPlayers);
    m_board.sendBoardKeysToObjects(*this, level);
    connectToTeleports();
}
//__________________________________________________________________
void Data::setData(const sf::Vector2f &location, const char object)
{
    switch (object)
    {
    case KING:
        m_players[KING_BOARD_OBJECT] = std::make_unique<KingObject>(location, King);
        break;

    case MAGE:
        m_players[MAGE_BOARD_OBJECT] = std::make_unique<MageObject>(location, Mage);
        break;

    case WARRIOR:
        m_players[WARRIOR_BOARD_OBJECT] = std::make_unique<WarriorObject>(location, Warrior);
        break;

    case THIEF:
        m_players[THIEF_BOARD_OBJECT] = std::make_unique<ThiefObject>(location, Thief);
        break;

    case DWARF:
        m_dwarfs.push_back(std::make_unique<DwarfObject>(location, Dwarf));
        break;

    case WALL:
        m_statics.push_back(std::make_unique<WallObject>(location, Wall));
        break;

    case CROWN:
        m_statics.push_back(std::make_unique<CrownObject>(location, Crown));
        break;

    case FIRE:
        m_statics.push_back(std::make_unique<FireObject>(location, Fire));
        break;

    case GATE:
        m_statics.push_back(std::make_unique<GateObject>(location, Gate));
        break;

    case GATE_KEY:
        m_statics.push_back(std::make_unique<KeyObject>(location, Key));
        break;

    case MONSTER:
        m_statics.push_back(std::make_unique<MonsterObject>(location, Monster));
        break;

    case TELEPORT:
        m_teleports.push_back(std::make_unique<TeleporterObject>(location, Teleport, true));
        break;

    case GIFT:
        m_statics.push_back(std::make_unique<TimeGiftObject>(location, Gift));
        break;

    case REMOVE_DWARFS:
        m_statics.push_back(std::make_unique<RemoveDwarfsObject>(location, Gift));
    default:
        break;
    }
}
//_____________________________
void Data::connectToTeleports()
{
    // combinning the teleports randomly to each other
    int index = m_teleports.size() - 1, random;
    for (int i = 0; i < m_teleports.size(); i++)
    {
        // promising that a teleport won't be matched to it self
        while ((random = rand() % index) == i)
            ;
        m_teleports[i]->setConnectedTeleport(m_teleports[random]->getPosition());
        m_teleports[i]->setNextIndex(random);
    }
}
//_______________________
void Data::clearObjects()
{
    m_players.clear();
    m_statics.clear();
    m_teleports.clear();
    if(m_dwarfs.size()!=0)
        m_dwarfs.clear();
}
//__________________________
bool Data::endOfFile() const
{
    return m_board.checkEndOfFile();
}
//_____________________
void Data::clearBoard()
{
    m_board.clearBoard();
}
//____________________________________________________________________________________________
void Data::moveData(const sf::Event &event, const sf::Time &deltaTime, const int activePlayer)
{
    m_activePlayer = activePlayer;
    movePlayerObject(event, deltaTime);
    moveDwarfsObjects(event, deltaTime);
    checkToOpenTeleport(*m_players[m_activePlayer]);
    checkPlayerCollision(*m_players[m_activePlayer]);
    checkDwarfCollision(event);
    handleDaedObjects();
}
//____________________________________________________________________________
void Data::movePlayerObject(const sf::Event &event, const sf::Time &deltaTime)
{
    m_players[m_activePlayer]->move(deltaTime, event);
}
//_____________________________________________________________________________
void Data::moveDwarfsObjects(const sf::Event &event, const sf::Time &deltaTime)
{
    static sf::Clock canDwarfMove;
    for (auto &dwarfs : m_dwarfs)
    {
        if (canDwarfMove.getElapsedTime().asSeconds() > 1.5f)
        {
            static_cast<DwarfObject *>(dwarfs.get())->setDirection();
            m_changeDwarfDir = true;
        }
        dwarfs->move(deltaTime, event);
    }
    if (m_changeDwarfDir)
    {
        m_changeDwarfDir = false;
        canDwarfMove.restart();
    }
}
//___________________________________________________________
void Data::checkPlayerCollision(MovingObjects &activePlayer)
{
    for (auto &unmovable : m_statics)
        if (activePlayer.checkCollision(*unmovable))
            activePlayer.collide(*unmovable);

    for (auto &movalbe : m_players)
        if (activePlayer.checkCollision(*movalbe) && &activePlayer != &(*movalbe))
            activePlayer.setPosition();

    for (auto &teleports : m_teleports)
        if (activePlayer.checkCollision(*teleports) && teleports->isTelOpen() &&
            noOtherPlayerIsOnNextTeleport(teleports->getNextTelIndex()))
        {
            activePlayer.collide(*teleports);
            m_teleports[teleports->getNextTelIndex()]->setLock(false);
            m_teleportIndex = teleports->getNextTelIndex();
        }
}
//____________________________________________________
void Data::checkDwarfCollision(const sf::Event &event)
{
    for (auto &dwarfs : m_dwarfs)
        for (auto &statics : m_statics)
            if (dwarfs->checkCollision(*statics))
                dwarfs->collide(*statics);

    // for (auto &dwarfs : m_dwarfs)
    //     for (auto &players : m_players)
    //         if (dwarfs->checkCollision(*players))
    //             dwarfs->collide(*players);
}
//_________________________________________________________
void Data::checkToOpenTeleport(MovingObjects &activePlayer)
{
    // while the player is on the teleport, the teleport stays closed,
    //  and the collision is not checked
    if (activePlayer.checkCollision(*m_teleports[m_teleportIndex]))
        return;
    m_teleports[m_teleportIndex]->setLock(true);
}
//_____________________________________________________________________
bool Data::noOtherPlayerIsOnNextTeleport(const int nextTelelport) const
{
    for (int i = 0; i < m_players.size(); i++)
    {
        if (i == m_activePlayer)
            continue;
        if (m_players[i]->checkCollision(*m_teleports[nextTelelport]))
            return false;
    }
    return true;
}
//____________________________
void Data::handleDaedObjects()
{
    for (auto &unmovable : m_statics)
    {
        if (typeid(*unmovable) == typeid(MonsterObject) && unmovable->isDead())
            setData(unmovable->getPosition(), GATE_KEY);
        else if (typeid(*unmovable) == typeid(RemoveDwarfsObject) && unmovable->isDead())
            removeDwarfs();
        else if (typeid(*unmovable) == typeid(TimeGiftObject) && unmovable->isDead())
            m_controller->setTime(getTimeForGift());
    }

    std::erase_if(m_statics, [](auto &staticObject)
                  { return staticObject->isDead(); });

    std::erase_if(m_dwarfs, [](auto &dwarfsObject)
                  { return dwarfsObject->isDead(); });
}
//_______________________
void Data::removeDwarfs()
{
    for (auto &dwarfs : m_dwarfs)
        dwarfs->setIsDead();
}
//_________________________
bool Data::wonLevel() const
{
    return static_cast<KingObject *>(m_players[KING_BOARD_OBJECT].get())->getKingOnThrone();
}
//____________________________
bool Data::thiefHasKey() const
{
    return static_cast<ThiefObject *>(m_players[THIEF_BOARD_OBJECT].get())->doesThiefhasKey();
}
//_________________________________________________________________________________________________
void Data::drawObjects(sf::RenderWindow &window, const bool pauseButton, const bool gameOver) const
{
    for (auto &unmovable : m_statics)
    {
        if (!pauseButton && !gameOver)
            if (typeid(*unmovable) == typeid(FireObject))
                unmovable->updateSpriteRect(7, 55, 25, 60);
            if (typeid(*unmovable) == typeid(KeyObject))
                unmovable->updateSpriteRect(11, 60, 50, 60);
            if (typeid(*unmovable) == typeid(MonsterObject))
                unmovable->updateSpriteRect(8, 65, 50, 65);
            if (typeid(*unmovable) == typeid(TimeGiftObject)||typeid(*unmovable) == typeid(RemoveDwarfsObject))
                unmovable->updateSpriteRect(2, 49, 50, 50);

        unmovable->drawShape(window);
    }

    for (auto &player : m_players)
        player->drawShape(window);

    for (auto &dwarfs : m_dwarfs)
        dwarfs->drawShape(window);

    for (auto &teleport : m_teleports)
    {
        if (!pauseButton && !gameOver)
            teleport->updateSpriteRect(5, 48, 48, 60);
        teleport->drawShape(window);
    }
}
//________________________
int Data::getTimeForGift()
{
    return (rand() % 30 + (-30));
}