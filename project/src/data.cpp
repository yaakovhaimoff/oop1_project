#include "data.hpp"
// #include "board.hpp"

//_________________________
void Data::setDataObjects()
{
    m_players.resize(numOfPlayers);
    m_board.setObjectsFromBoard(*this);
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
        m_players.push_back(std::make_unique<DwarfObject>(location, Dwarf));
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
    for (int i = numOfPlayers; i < m_players.size(); i++)
    {
        if (canDwarfMove.getElapsedTime().asSeconds() > 1.5f)
        {
            static_cast<DwarfObject *>(m_players[i].get())->setDirection();
            m_changeDwarfDir = true;
        }
        // m_players[i]->move(deltaTime, event);
        static_cast<DwarfObject *>(m_players[i].get())->moving(deltaTime, event, m_changeDwarfDir);
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
    for (int i = numOfPlayers; i < m_players.size(); i++)
        for (int j = 0; j < m_statics.size(); j++)
            if (m_players[i]->checkCollision(*m_statics[j]))
                m_players[i]->collide(*m_statics[j]);
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
    for (int i = 0; i < numOfPlayers; i++)
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
        //  else if (typeid(*unmovable) == typeid(TimeGiftObject) && unmovable->isDead())
        //      m_gameTime += getTimeForGift();
    }

    std::erase_if(m_statics, [](auto &staticObject)
                  { return staticObject->isDead(); });
}
//_______________________
void Data::removeDwarfs()
{
    int size = m_players.size() - numOfPlayers;
    for (int i = numOfPlayers; size < m_players.size();)
        m_players.erase(m_players.begin() + i);
}
//_________________________
bool Data::wonLevel() const
{
    for (auto &unmovable : m_statics)
        if (typeid(*unmovable) == typeid(CrownObject))
            return false;
    return true;
}
//____________________________
bool Data::thiefHasKey() const
{
    return dynamic_cast<ThiefObject *>(m_players[THIEF_BOARD_OBJECT].get())->doesThiefhasKey();
}
//_____________________________________________________________________________
void Data::drawObjects(sf::RenderWindow &window, const bool pauseButton) const
{
    for (auto &unmovable : m_statics)
    {
        if (!pauseButton)
            if (typeid(*unmovable) == typeid(CrownObject))
                unmovable->updateSpriteRect(3, 72, 65, 50);
            else if (typeid(*unmovable) == typeid(FireObject))
                unmovable->updateSpriteRect(8, 25, 25, 50);
            else if (typeid(*unmovable) == typeid(KeyObject))
                unmovable->updateSpriteRect(11, 60, 50, 60);
            else if (typeid(*unmovable) == typeid(MonsterObject))
                unmovable->updateSpriteRect(8, 65, 52, 58);

        unmovable->drawShape(window);
    }

    for (auto &player : m_players)
        player->drawShape(window);

    for (auto &teleport : m_teleports)
    {
        if (!pauseButton)
            teleport->updateSpriteRect(5, 48, 48, 60);
        teleport->drawShape(window);
    }

    window.display();
    Resources::instance().stopLoop(menuSound);
    window.setFramerateLimit(12);
}
//________________________
int Data::getTimeForGift()
{
	return (rand() % 30 + (-30));
}