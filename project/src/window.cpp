#include "window.hpp"

//______________
Window::Window()
{
	setFont();
	setMenu();
	setHelp();
	// setSound();
	setPlay();
}
//____________________
void Window::setFont()
{
	auto font = Resources::pToRsc().getFont();
	m_font = (*font);
}
//____________________
void Window::setSound()
{
	for (auto i = 0; i < SOUNDS_NAMES.size(); i++)
	{
		auto Sound = Resources::pToRsc().getSound(i);
		m_sounds[i].setBuffer(*Sound);
	}
	m_sounds[GameSound].play();
}
//____________________
void Window::setMenu()
{
	auto texture = Resources::pToRsc().getTexture(MenuBackground);
	m_background[MENU].setTexture(*texture);
	// set rectangle for the menu buttons and texts
	for (int row = 1; row < AmountOfWindows; row++)
	{
		m_menuRects[row - 1] = sf::RectangleShape({220, 120});
		m_menuRects[row - 1].setFillColor(sf::Color::Transparent);
		m_menuRects[row - 1].setOutlineColor(sf::Color::White);
		m_menuRects[row - 1].setOutlineThickness(4);
		m_menuRects[row - 1].setPosition(sf::Vector2f((CELL + SPACE) * row, SPACE + 100));

		m_menuText[row - 1].setFont(m_font);
		m_menuText[row - 1].setCharacterSize(100);
		m_menuText[row - 1].setFillColor(sf::Color::White);
		m_menuText[row - 1].setPosition(sf::Vector2f((CELL + SPACE + 4) * row, SPACE + 100));
		m_menuText[row - 1].setString(menu_names[row - 1]);
	}
	sf::Text menuButtonText;
	// set the game name
	m_gameName.setFont(m_font);
	m_gameName.setCharacterSize(150);
	m_gameName.setFillColor(sf::Color::White);
	m_gameName.setPosition(sf::Vector2f(560, 100));
	m_gameName.setString("SAVE THE KING");
}
//____________________
void Window::setHelp()
{
	auto texture = Resources::pToRsc().getTexture(HelpScreen);
	m_background[HELP].setTexture(*texture);
	// set rectangle for the help back button
	m_helpRect = sf::RectangleShape({160, 90});
	m_helpRect.setFillColor(sf::Color::Transparent);
	m_helpRect.setOutlineColor(sf::Color::White);
	m_helpRect.setOutlineThickness(4);
	m_helpRect.setPosition(sf::Vector2f(20, 20));
	// set back string text
	m_helpText.setFont(m_font);
	m_helpText.setCharacterSize(80);
	m_helpText.setFillColor(sf::Color::White);
	m_helpText.setPosition(sf::Vector2f(25, 20));
	m_helpText.setString("BACK");
}
//____________________
void Window::setPlay()
{
	auto m_texture = Resources::pToRsc().getTexture(BoardBackground);
	m_gameSprite.setTexture(*(m_texture));
	m_gameSprite.setScale(1, (float)1);
	// setting the inforamation rectangle
	// m_infoRect = sf::RectangleShape({165, 300});
	m_infoRect = sf::RectangleShape({280, 280});
	m_infoRect.setPosition(100, 200);
	m_infoRect.setOutlineColor(sf::Color::Black);
	m_infoRect.setOutlineThickness(4);
	m_infoRect.setFillColor(sf::Color(192, 192, 192, 50));
}
//____________________________________________________________________________
void Window::catchMouseEvent(sf::RenderWindow &window, const sf::Event &event)
{
	if (m_currentWindow[MENU])
		checkMouseOnMenu(event);
	else if (m_currentWindow[HELP])
		checkMouseOnBack(event);
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

	for (int row = 0; row < AmountOfWindows - 1; row++)
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
}
//_________________________________________________________
void Window::checkMenuPressed(const sf::Vector2f &location)
{
	auto menuButton = sf::RectangleShape({220, 120});

	for (int row = 1; row < AmountOfWindows; row++)
	{
		menuButton.setPosition(sf::Vector2f((CELL + SPACE) * row, SPACE + 100));

		if (menuButton.getGlobalBounds().contains(location))
		{
			m_currentWindow[MENU] = false;
			m_currentWindow[row] = true;
			m_sounds[CLICK_SOUND].play();
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
		m_sounds[CLICK_SOUND].play();
	}
}
//____________________________________________________
void Window::drawWindow(sf::RenderWindow &window) const
{
	if (m_currentWindow[MENU])
		drawMenu(window);
	else if (m_currentWindow[HELP])
		drawHelp(window);
}
//__________________________________________________
void Window::drawMenu(sf::RenderWindow &window) const
{
	window.clear();
	window.draw(m_background[MENU]);
	window.draw(m_gameName);
	for (int row = 1; row < AmountOfWindows; row++)
	{
		window.draw(m_menuRects[row - 1]);
		window.draw(m_menuText[row - 1]);
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
//___________________________________________________________________________________________________________________________
void Window::drawPlay(sf::RenderWindow &window, const sf::Clock &clock, const sf::Time &time, const int level, const bool key,
					  const std::vector<std::unique_ptr<MovingObjects>> &players,
					  const std::vector<std::unique_ptr<StaticObjects>> &statics,
					  const std::vector<std::unique_ptr<TeleporterObject>> &teleports) const
{
	window.clear();
	window.draw(m_gameSprite);
	drawObjects(window, players, statics, teleports);
	drawLevelInfo(window, clock, time, level, key);
	window.display();
	window.setFramerateLimit(12);
}
//________________________________________________
void Window::drawObjects(sf::RenderWindow &window,
						 const std::vector<std::unique_ptr<MovingObjects>> &players,
						 const std::vector<std::unique_ptr<StaticObjects>> &statics,
						 const std::vector<std::unique_ptr<TeleporterObject>> &teleports) const
{
	for (auto &unmovable : statics)
	{
		if (typeid(*unmovable) == typeid(WallObject))
			unmovable->updateSpriteRect(0, 0, 55, 60);
		else if (typeid(*unmovable) == typeid(CrownObject))
			unmovable->updateSpriteRect(3, 72, 65, 50);
		else if (typeid(*unmovable) == typeid(FireObject))
			unmovable->updateSpriteRect(9, 16, 30, 80);
		else if (typeid(*unmovable) == typeid(KeyObject))
			unmovable->updateSpriteRect(11, 60, 50, 60);
		else if (typeid(*unmovable) == typeid(MonsterObject))
			unmovable->updateSpriteRect(8, 40, 48, 58);
		else if (typeid(*unmovable) == typeid(TimeGiftObject) || typeid(*unmovable) == typeid(RemoveDwarfsObject))
			unmovable->updateSpriteRect(2, 50, 46, 60);

		unmovable->drawShape(window);
	}

	for (auto &movable : players)
		movable->drawShape(window);

	for (auto &teleport : teleports)
	{
		teleport->updateSpriteRect(2, 48, 46, 60);
		teleport->drawShape(window);
	}
}
//__________________________________________________________________________
void Window::drawLevelInfo(sf::RenderWindow &window, const sf::Clock &clock,
						   const sf::Time &levelTime, const int level, const bool key) const
{
	// information on board rectangle
	window.draw(m_infoRect);
	// number of level text
	std::string textString = "Level: ";
	textString += std::to_string(level + 1);
	sf::Text levelText, timeText, keyText;
	levelText.setFont(m_font);
	levelText.setCharacterSize(50);
	levelText.setPosition(110, 220);
	levelText.setString(textString);
	window.draw(levelText);
	// time text
	sf::Time gameTime = levelTime - clock.getElapsedTime();
	int time = gameTime.asSeconds();
	textString = "Time 0";
	textString += std::to_string(time / 60); // time / 60 for minutes
	textString += " : ";
	textString += std::to_string(time % 60); // time % 60 for seconds
	timeText.setFont(m_font);
	timeText.setString(textString);
	timeText.setCharacterSize(40);
	timeText.setPosition(110, 320);
	window.draw(timeText);
	// key text
	key ? textString = "Thief has key" : textString = "Thief does not have key";
	keyText.setFont(m_font);
	keyText.setString(textString);
	keyText.setCharacterSize(30);
	keyText.setPosition(110, 400);
	window.draw(keyText);
}

//___________________________
bool Window::isPlaying() const
{
	return m_currentWindow[PLAY];
}
//________________________
bool Window::isExit() const
{
	return m_currentWindow[EXIT];
}
//_________________________
void Window::setIsPlaying()
{
	m_currentWindow[PLAY] = false;
	m_currentWindow[MENU] = true;
}
