#include "window.hpp"

//______________
Window::Window()
	: m_pauseButton(false), m_soundButton(false)
{
	Resources::instance().playInLoop(menuSound);
	setMenu();
	setHelp();
	setPlay();
	setPause();
	setSound();
	setSelectLevel();
	setActivePlayerInfo();
}
//_____________________________
void Window::setIsLevelSelect()
{
	m_levelSelect = false;
	m_currentWindow[PLAY] = true;
}
//____________________
void Window::setMenu()
{
	m_background[MENU].setTexture(Resources::instance().getTexture(MenuBackground));
	// set rectangle for the menu buttons and texts
	for (int row = 0; row < AmountOfWindows; row++)
	{
		m_menuRects[row] = sf::RectangleShape({220, 120});
		m_menuRects[row].setFillColor(sf::Color::Transparent);
		m_menuRects[row].setOutlineColor(sf::Color::White);
		m_menuRects[row].setOutlineThickness(4);
		m_menuRects[row].setPosition(sf::Vector2f((CELL + SPACE) * (row + 1), SPACE + 100));

		m_menuText[row].setFont(Resources::instance().getFont());
		m_menuText[row].setCharacterSize(100);
		m_menuText[row].setFillColor(sf::Color::White);
		m_menuText[row].setPosition(sf::Vector2f((CELL + SPACE + 4) * (row + 1), SPACE + 100));
		m_menuText[row].setString(menu_names[row]);
	}
	sf::Text menuButtonText;
	// set the game name
	m_gameName.setFont(Resources::instance().getFont());
	m_gameName.setCharacterSize(150);
	m_gameName.setFillColor(sf::Color::White);
	m_gameName.setPosition(sf::Vector2f(560, 100));
	m_gameName.setString("SAVE THE KING");
}
//____________________
void Window::setHelp()
{
	m_background[HELP].setTexture(Resources::instance().getTexture(HelpScreen));
	// set rectangle for the help back button
	m_helpRect = sf::RectangleShape({160, 90});
	m_helpRect.setFillColor(sf::Color::Transparent);
	m_helpRect.setOutlineColor(sf::Color::White);
	m_helpRect.setOutlineThickness(4);
	m_helpRect.setPosition(sf::Vector2f(20, 20));
	// set back string text
	m_helpText.setFont(Resources::instance().getFont());
	m_helpText.setCharacterSize(80);
	m_helpText.setFillColor(sf::Color::White);
	m_helpText.setPosition(sf::Vector2f(25, 20));
	m_helpText.setString("BACK");
}
//____________________
void Window::setPlay()
{
	// setting the levels backgrounds
	for (int i = 0; i < LEVELS; i++)
		m_gameSprite[i].setTexture(Resources::instance().getTexture(i));

	m_gameSprite[0].setScale(1, (float)1);
	m_gameSprite[1].setScale(3, (float)3);
	m_gameSprite[2].setScale(3, (float)3);
	// setting the inforamation rectangle
	// m_infoRect = sf::RectangleShape({165, 300});
	m_infoRect = sf::RectangleShape({295, 450});
	m_infoRect.setPosition(100, 200);
	m_infoRect.setOutlineColor(sf::Color::Black);
	m_infoRect.setOutlineThickness(4);
	m_infoRect.setFillColor(sf::Color(192, 192, 192, 50));
}
//_____________________
void Window::setPause()
{
	m_pause.setTexture(Resources::instance().getTexture(Pause));
	m_pause.setPosition(30, 30);
	m_paused.setTexture(Resources::instance().getTexture(Paused));
	m_paused.setPosition(20, 200);
	m_paused.setScale(2.8, 2.8);
}
//_____________________
void Window::setSound()
{
	m_soundOn.setTexture(Resources::instance().getTexture(soundOn));
	m_soundOn.setPosition(200, 40);
	m_soundOn.setScale(1.3, 1.3);
	m_soundOff.setTexture(Resources::instance().getTexture(soundOff));
	m_soundOff.setPosition(200, 40);
	m_soundOff.setScale(1.3, 1.3);
}
//________________________________
void Window::setActivePlayerInfo()
{
	// active player name on board
	std::string textString = "Active player:";
	m_activePlayerText.setFont(Resources::instance().getFont());
	m_activePlayerText.setString(textString);
	m_activePlayerText.setCharacterSize(50);
	m_activePlayerText.setPosition(110, 450);
	// setting the spriite of the active player
	for (int i = 0; i < numOfPlayers; i++)
	{
		m_activePlayer[i].setTexture(Resources::instance().getTexture(i + 6));
		m_activePlayer[i].setPosition(265, 540);
		m_activePlayer[i].setTextureRect(sf::IntRect(0, 0, float(58.66), float(58.5)));
		m_activePlayer[i].setScale(1.5, 1.5);
	}
}
//____________________________________________________________________________
void Window::catchMouseEvent(sf::RenderWindow &window, const sf::Event &event)
{
	if (m_currentWindow[MENU])
		checkMouseOnMenu(event);
	else if (m_currentWindow[HELP])
		checkMouseOnBack(event);
	else if (m_levelSelect)
		checkMouseOnLevelSelect(event);
}
//___________________________________________________
void Window::checkMouseOnBack(const sf::Event &event)
{
	auto location = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);

	if (m_helpRect.getGlobalBounds().contains(location))
		m_helpRect.setFillColor(sf::Color::Black);
	else
		m_helpRect.setFillColor(sf::Color::Transparent);
}
//___________________________________________________
void Window::checkMouseOnMenu(const sf::Event &event)
{
	auto location = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);

	for (int row = 0; row < AmountOfWindows; row++)
	{
		if (m_menuRects[row].getGlobalBounds().contains(location))
		{
			m_menuRects[row].setFillColor(sf::Color::Black);
			break;
		}
		else
			m_menuRects[row].setFillColor(sf::Color::Transparent);
	}
}
//___________________________________________________________
void Window::handleClickInWindow(const sf::Vector2f &location)
{
	if (m_currentWindow[MENU])
		checkMenuPressed(location);
	else if (m_currentWindow[HELP])
		checkHelpPressed(location);
	else if (m_currentWindow[PLAY])
		checkPlayPressed(location);
	else if (m_levelSelect)
		checkLevelPressed(location);
}
//_________________________________________________________
void Window::checkMenuPressed(const sf::Vector2f &location)
{
	auto menuButton = sf::RectangleShape({220, 120});

	for (int row = 0; row < AmountOfWindows; row++)
	{
		menuButton.setPosition(sf::Vector2f((CELL + SPACE) * (row + 1), SPACE + 100));

		if (menuButton.getGlobalBounds().contains(location))
		{
			Resources::instance().playSound(ClickSound);
			m_currentWindow[MENU] = false;
			if (row + 1 == PLAY)
				m_levelSelect = true;
			else
				m_currentWindow[row + 1] = true;
			break;
		}
	}
}
//_________________________________________________________
void Window::checkHelpPressed(const sf::Vector2f &location)
{
	auto backButton = sf::RectangleShape({160, 90});
	backButton.setPosition(sf::Vector2f(20, 20));
	if (backButton.getGlobalBounds().contains(location))
	{
		m_currentWindow[HELP] = false;
		m_currentWindow[MENU] = true;
		Resources::instance().playSound(ClickSound);
	}
}
//_________________________________________________________
void Window::checkPlayPressed(const sf::Vector2f &location)
{
	checkPausePressed(location);
	checkSoundPressed(location);
}
//_________________________________________________________
void Window::checkPausePressed(const sf::Vector2f &location)
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
//_________________________________________________________
void Window::checkSoundPressed(const sf::Vector2f &location)
{
	if (!m_soundButton && m_soundOn.getGlobalBounds().contains(location))
	{
		m_soundButton = true;
		Resources::instance().playSound(ClickSound);
		Resources::instance().stopLoop(GameSound);
		return;
	}
	else if (m_soundButton && m_soundOn.getGlobalBounds().contains(location))
	{
		m_soundButton = false;
		Resources::instance().playSound(ClickSound);
		Resources::instance().playInLoop(GameSound);
		return;
	}
}
//____________________________________________________
void Window::drawWindow(sf::RenderWindow &window) const
{
	if (m_currentWindow[MENU])
		drawMenu(window);
	else if (m_currentWindow[HELP])
		drawHelp(window);
	else if (m_levelSelect)
		drawSelectLevel(window);
}
//__________________________________________________
void Window::drawMenu(sf::RenderWindow &window) const
{
	window.clear();
	window.draw(m_background[MENU]);
	window.draw(m_gameName);
	for (int row = 0; row < AmountOfWindows; row++)
	{
		window.draw(m_menuRects[row]);
		window.draw(m_menuText[row]);
	}
	window.display();
}
//__________________________________________________
void Window::drawHelp(sf::RenderWindow &window) const
{
	window.clear();
	window.draw(m_background[HELP]);
	window.draw(m_helpRect);
	window.draw(m_helpText);
	window.display();
}
//_______________________________________________________________________________________________
void Window::drawPlayWindow(sf::RenderWindow &window, const int &time, const int level, const bool key,
							const int player) const
{
	window.draw(m_gameSprite[level]);
	m_soundButton ? window.draw(m_soundOff) : window.draw(m_soundOn); 
	drawLevelInfo(window, time, level, key);
	drawActivePlayer(window, player);
}
//_____________________________________________________
void Window::drawPauseMessage(sf::RenderWindow &window)
{
	m_pauseButton ? drawPasused(window) : drawPasuse(window);
}
//____________________________________________________________________________
void Window::drawActivePlayer(sf::RenderWindow &window, const int player) const
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
	nameText.setCharacterSize(50);
	nameText.setPosition(110, 510);
	window.draw(m_activePlayerText);
	window.draw(nameText);
	window.draw(m_activePlayer[player]);
}
//____________________________________________________
void Window::drawPasuse(sf::RenderWindow &window) const
{
	window.draw(m_pause);
}
//____________________________________________________
void Window::drawPasused(sf::RenderWindow &window) const
{
	window.draw(m_paused);
}
//___________________________
bool Window::isPlaying() const
{
	return m_currentWindow[PLAY];
}
//__________________________
bool Window::isPause() const
{
	return m_pauseButton;
}
//________________________
bool Window::isExit() const
{
	return m_currentWindow[EXIT];
}
//__________________________________________________________________________
void Window::drawLevelInfo(sf::RenderWindow &window, const int &levelTime,
						   const int level, const bool key) const
{
	// information on board rectangle
	window.draw(m_infoRect);
	// number of level text
	std::string textString = "Level: ";
	textString += std::to_string(level + 1);
	sf::Text levelText, timeText, keyText;
	levelText.setFont(Resources::instance().getFont());
	levelText.setCharacterSize(50);
	levelText.setPosition(110, 220);
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
	timeText.setCharacterSize(40);
	timeText.setPosition(110, 320);
	window.draw(timeText);
	// key text
	key ? textString = "Thief has key" : textString = "Thief does not have key";
	keyText.setFont(Resources::instance().getFont());
	keyText.setString(textString);
	keyText.setCharacterSize(30);
	keyText.setPosition(110, 400);
	window.draw(keyText);
}
//______________________________________________________________
void Window::gameOverLevelMessage(sf::RenderWindow &window) const
{
	std::string gameOver = "Game Over!";
	sf::Text gameOverText;
	gameOverText.setFont(Resources::instance().getFont());
	gameOverText.setString(gameOver);
	gameOverText.setCharacterSize(100);
	gameOverText.setPosition(750, 50);
	sf::Clock clock;
	while (clock.getElapsedTime().asSeconds() < 2)
	{
		window.draw(gameOverText);
		window.display();
	}
}
//___________________________
void Window::setSelectLevel()
{
	// set rectangle for the Select Level buttons and texts
	for (int row = 0; row < AmountOfWindows; row++)
	{
		// set Texts
		m_selectLevelText[row].setFont(Resources::instance().getFont());
		m_selectLevelText[row].setCharacterSize(100);
		m_selectLevelText[row].setFillColor(sf::Color::White);
		m_selectLevelText[row].setPosition(sf::Vector2f(800, 200 * (row + 1.8)));
		m_selectLevelText[row].setString(selectLevelNames[row]);
	}
	// set the game name
	m_selectLevelName.setFont(Resources::instance().getFont());
	m_selectLevelName.setCharacterSize(180);
	m_selectLevelName.setFillColor(sf::Color::Black);
	m_selectLevelName.setPosition(sf::Vector2f(500, 80));
	m_selectLevelName.setOutlineColor(sf::Color(0, 0, 0, 100));
	m_selectLevelName.setOutlineThickness(5);
	m_selectLevelName.setString("Select Level");

	m_levelSelectBack = Resources::instance().getSprite(SelecetLevel);
	m_levelSelectBack.setScale(2.5, 2);
}
//__________________________________________________
void Window::drawSelectLevel(sf::RenderWindow &window) const
{
	window.clear();
	window.draw(m_levelSelectBack);
	window.draw(m_selectLevelName);
	for (int row = 0; row < LEVELS; row++)
		window.draw(m_selectLevelText[row]);
	window.display();
}
//__________________________________________________________
void Window::checkMouseOnLevelSelect(const sf::Event &event)
{
	auto location = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);

	for (int row = 0; row < LEVELS; row++)
	{
		if (m_selectLevelText[row].getGlobalBounds().contains(location))
		{
			m_selectLevelText[row].setColor(sf::Color::Black);
			break;
		}
		else
			m_selectLevelText[row].setColor(sf::Color::White);
	}
}
//_________________________________________________________
void Window::checkLevelPressed(const sf::Vector2f &location)
{
	auto levelSelectBottun = sf::RectangleShape({300, 130});

	for (int row = 0; row < LEVELS; row++)
	{
		levelSelectBottun.setPosition(m_selectLevelText[row].getPosition());
		if (levelSelectBottun.getGlobalBounds().contains(location))
		{
			m_levelSelected = row;
			Resources::instance().playSound(ClickSound);
			setIsLevelSelect();
			break;
		}
	}
}