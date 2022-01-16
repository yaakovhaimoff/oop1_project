#include "windowInclude/playWindow.hpp"

//_____________________
PlayWindow::PlayWindow()
	: m_pauseButton(false), m_soundButton(false)
{
	Resources::instance().playInLoop(menuSound);
	setPlay();
	setPause();
	setSound();
	setActivePlayerInfo();
}
//_______________________
void PlayWindow::setPlay()
{
	// setting the levels backgrounds
	for (int i = 0; i < LEVELS; i++)
		m_gameSprite[i].setTexture(Resources::instance().getTexture(i));
	// setting the inforamation rectangle
	m_infoRect = sf::RectangleShape({1900, 150});
	m_infoRect.setPosition(10, 20);
	m_infoRect.setOutlineColor(sf::Color::Black);
	m_infoRect.setOutlineThickness(4);
	m_infoRect.setFillColor(sf::Color(192, 192, 192, 50));
	m_key.setTexture(Resources::instance().getTexture(Key));
	m_key.setPosition(1048, 50);
	m_key.setTextureRect(sf::IntRect(0, 0, 50, 60));
	m_key.setScale(1.5, 1.5);
	m_noKey.setTexture(Resources::instance().getTexture(noKey));
	m_noKey.setPosition(1050, 50);
}
//________________________
void PlayWindow::setPause()
{
	m_pause.setTexture(Resources::instance().getTexture(Pause));
	m_pause.setPosition(0, 30);
	m_paused.setTexture(Resources::instance().getTexture(Paused));
	m_paused.setPosition(20, 200);
	m_paused.setScale(2.8, 2.8);
}
//_________________________
void PlayWindow::setSound()
{
	m_sound.setTexture(Resources::instance().getTexture(soundOn));
	m_sound.setPosition(150, 40);
	m_sound.setScale(1.3, 1.3);
}
//____________________________________
void PlayWindow::setActivePlayerInfo()
{
	// active player name on board
	std::string textString = "Active player:";
	m_activePlayerText.setFont(Resources::instance().getFont());
	m_activePlayerText.setString(textString);
	m_activePlayerText.setCharacterSize(60);
	m_activePlayerText.setPosition(1230, 55);
	// setting the spriite of the active player
	for (int i = 0; i < numOfPlayers; i++)
	{
		m_activePlayer[i].setTexture(Resources::instance().getTexture(i + 6));
		m_activePlayer[i].setPosition(1800, 55);
		m_activePlayer[i].setTextureRect(sf::IntRect(0, 0, float(58.66), float(58.5)));
		m_activePlayer[i].setScale(1.5, 1.5);
	}
}
//_____________________________________________________________
void PlayWindow::checkPlayPressed(const sf::Vector2f &location)
{
	checkPausePressed(location);
	checkSoundPressed(location);
}
//______________________________________________________________
void PlayWindow::checkPausePressed(const sf::Vector2f &location)
{
	if (!m_pauseButton && m_pause.getGlobalBounds().contains(location))
	{
		m_pauseButton = true;
		Resources::instance().playSound(ClickSound);
	}
	if (m_pauseButton && m_paused.getGlobalBounds().contains(location))
	{
		m_pauseButton = false;
		Resources::instance().playSound(ClickSound);
	}
}
//______________________________________________________________
void PlayWindow::checkSoundPressed(const sf::Vector2f &location)
{
	if (m_sound.getGlobalBounds().contains(location))
	{
		if (!m_soundButton)
		{
			m_sound.setTexture(Resources::instance().getTexture(soundOff));
			Resources::instance().stopLoop(GameSound);
		}
		else
		{
			m_sound.setTexture(Resources::instance().getTexture(soundOn));
			Resources::instance().playInLoop(GameSound);
		}
		Resources::instance().playSound(ClickSound);
		m_soundButton = !m_soundButton;
	}
}
//________________________________________________________________________________________________________
void PlayWindow::drawPlayWindow(sf::RenderWindow &window, const int &time, const int level, const bool key,
							const int player) const
{
	window.draw(m_gameSprite[level]);
	window.draw(m_sound);
	drawLevelInfo(window, time, level, key);
	drawActivePlayer(window, player);
}
//______________________________________________________________
void PlayWindow::drawPauseMessage(sf::RenderWindow &window)const
{
	m_pauseButton ? drawPasused(window) : drawPasuse(window);
}
//_________________________________________________________________________________
void PlayWindow::drawActivePlayer(sf::RenderWindow &window, const int player) const
{
	sf::Text nameText;
	std::string name;
	switch (player)
	{
	case KING_BOARD_OBJECT:
		name = "KING";
		break;
	case MAGE_BOARD_OBJECT:
		name = "MAGE";
		break;
	case WARRIOR_BOARD_OBJECT:
		name = "WARRIOR";
		break;
	case THIEF_BOARD_OBJECT:
		name = "THIEF";
		break;
	}
	nameText.setFont(Resources::instance().getFont());
	nameText.setString(name);
	nameText.setCharacterSize(60);
	nameText.setPosition(1570, 55);
	window.draw(m_activePlayerText);
	window.draw(nameText);
	window.draw(m_activePlayer[player]);
}
//_________________________________________________________
void PlayWindow::drawPasuse(sf::RenderWindow &window) const
{
	window.draw(m_pause);
}
//__________________________________________________________
void PlayWindow::drawPasused(sf::RenderWindow &window) const
{
	window.draw(m_paused);
}
//__________________________
bool PlayWindow::isPause() const
{
	return m_pauseButton;
}
//__________________________________________________________________________
void PlayWindow::drawLevelInfo(sf::RenderWindow &window, const int &levelTime,
						   const int level, const bool key) const
{
	// information on board rectangle
	window.draw(m_infoRect);
	// number of level text
	std::string textString = "Level: ";
	textString += std::to_string(level + 1);
	sf::Text levelText, timeText, keyText;
	levelText.setFont(Resources::instance().getFont());
	levelText.setCharacterSize(60);
	levelText.setPosition(320, 55);
	levelText.setString(textString);
	window.draw(levelText);
	// time text
	int time = levelTime;
	textString = "Time 0";
	textString += std::to_string(time / 60); // time / 60 for minutes
	textString += " : ";
	textString += std::to_string(time % 60); // time % 60 for seconds
	timeText.setFont(Resources::instance().getFont());
	timeText.setString(textString);
	timeText.setCharacterSize(60);
	timeText.setPosition(560, 55);
	window.draw(timeText);
	// key text
	textString = "Thief:";
	keyText.setFont(Resources::instance().getFont());
	keyText.setString(textString);
	keyText.setCharacterSize(60);
	keyText.setPosition(900, 55);
	window.draw(keyText);
	window.draw(m_key);
	if (!key)
		window.draw(m_noKey);
}
//___________________________________________________________________
void PlayWindow::gameOverLevelMessage(sf::RenderWindow &window) const
{
	std::string gameOver = "Game Over!";
	sf::Text gameOverText;
	gameOverText.setFont(Resources::instance().getFont());
	gameOverText.setString(gameOver);
	gameOverText.setCharacterSize(200);
	gameOverText.setPosition(650, 400);
	sf::Clock clock;
	while (clock.getElapsedTime().asSeconds() < 2)
	{
		window.draw(gameOverText);
		window.display();
	}
}
//______________________________________________________________
void PlayWindow::winLevelMessage(sf::RenderWindow &window) const
{
	std::string gameOver = "You Win!";
	sf::Text winLevelText;
	winLevelText.setFont(Resources::instance().getFont());
	winLevelText.setString(gameOver);
	winLevelText.setCharacterSize(200);
	winLevelText.setPosition(650, 400);
	sf::Clock clock;
	while (clock.getElapsedTime().asSeconds() < 2)
	{
		window.draw(winLevelText);
		window.display();
	}
}