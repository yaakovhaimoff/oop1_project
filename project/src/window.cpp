#include "window.hpp"

//______________
Window::Window()
{
	this->setFont();
	this->setMenu();
	this->setHelp();
	this->setSound();
	this->setPlay();
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
		m_menuRects[row - 1] = sf::RectangleShape({ 220, 120 });
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
	m_helpRect = sf::RectangleShape({ 160, 90 });
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
	m_gameSprite.setScale(1, (float)1.4);
	// setting the inforamation rectangle
	m_infoRect = sf::RectangleShape({ 200, 400 });
	m_infoRect.setPosition(150, 200);
	m_infoRect.setOutlineColor(sf::Color::Black);
	m_infoRect.setOutlineThickness(4);
	m_infoRect.setFillColor(sf::Color(192, 192, 192, 50));
}
//____________________________________________________________________________
void Window::catchMouseEvent(sf::RenderWindow& window, const sf::Event& event)
{
	if (m_currentWindow[MENU])
		checkMouseOnMenu(event);
	else if (m_currentWindow[HELP])
		checkMouseOnBack(event);
}
//___________________________________________________
void Window::checkMouseOnBack(const sf::Event& event)
{
	auto location = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);

	if (m_helpRect.getGlobalBounds().contains(location))
		m_helpRect.setFillColor(sf::Color::Black);
	else
		m_helpRect.setFillColor(sf::Color::Transparent);
}
//___________________________________________________
void Window::checkMouseOnMenu(const sf::Event& event)
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
void Window::handleClickInWindow(const sf::Vector2f& location)
{
	if (m_currentWindow[MENU])
		this->checkMenuPressed(location);
	else if (m_currentWindow[HELP])
		this->checkHelpPressed(location);
}
//_________________________________________________________
void Window::checkMenuPressed(const sf::Vector2f& location)
{
	auto menuButton = sf::RectangleShape({ 220, 120 });

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
void Window::checkHelpPressed(const sf::Vector2f& location)
{
	auto backButton = sf::RectangleShape({ 160, 90 });
	backButton.setPosition(sf::Vector2f(20, 20));
	if (backButton.getGlobalBounds().contains(location))
	{
		m_currentWindow[HELP] = false;
		m_currentWindow[MENU] = true;
		m_sounds[CLICK_SOUND].play();
	}
}
//____________________________________________________
void Window::drawWindow(sf::RenderWindow& window)const
{
	if (m_currentWindow[MENU])
		this->drawMenu(window);
	else if (m_currentWindow[HELP])
		this->drawHelp(window);
}
//__________________________________________________
void Window::drawMenu(sf::RenderWindow& window)const
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
void Window::drawHelp(sf::RenderWindow& window)const
{
	window.clear();
	window.draw(m_background[HELP]);
	window.draw(m_helpRect);
	window.draw(m_helpText);
	window.display();
}
//___________________________________________________________________________________________
void Window::drawPlay(sf::RenderWindow& window, const sf::Clock& clock, const sf::Time& time,
	const std::vector<std::unique_ptr<MovingObjects>>& players,
	const std::vector<std::unique_ptr<StaticObjects>>& statics,
		const std::vector<std::unique_ptr<TeleporterObject>>& teleports)const
{
	window.clear();
	window.draw(m_gameSprite);
	this->drawObjects(window, players, statics, teleports);
	this->drawLevelInfo(window, clock, time);
	window.display();
}
//________________________________________________
void Window::drawObjects(sf::RenderWindow& window,
	const std::vector<std::unique_ptr<MovingObjects>>& players,
	const std::vector<std::unique_ptr<StaticObjects>>& statics,
		const std::vector<std::unique_ptr<TeleporterObject>>& teleports)const
{
	for (int i = 0; i < statics.size(); i++)
		statics[i]->drawShape(window);
	for (int i = 0; i < players.size(); i++)
		players[i]->drawShape(window);
	for (int i = 0; i < teleports.size(); i++)
		teleports[i]->drawShape(window);
}
//___________________________________________________________________________________________________________
void Window::drawLevelInfo(sf::RenderWindow& window, const sf::Clock& clock, const sf::Time& levelTime )const
{
	window.draw(m_infoRect);
	sf::Time gameTime = levelTime - clock.getElapsedTime();
	int time = gameTime.asSeconds();
	std::string timeString = "Time ";
	timeString += std::to_string(time / 60); // time / 60 for minutes 
	timeString += " : ";
	timeString += std::to_string(time % 60); // time % 60 for seconds
	sf::Text text;
	text.setFont(m_font);
	text.setPosition(160, 220);
	text.setCharacterSize(30);
	text.setString(timeString);
	window.draw(text);
}

//___________________________
bool Window::isPlaying()const
{
	return m_currentWindow[PLAY];
}
//________________________
bool Window::isExit()const
{
	return m_currentWindow[EXIT];
}