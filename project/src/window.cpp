#include "Window.hpp"

//______________
Window::Window()
{
	m_font.loadFromFile("font.ttf");
	this->setMenu();
	this->setHelp();
}
//____________________
void Window::setMenu()
{
	m_texture[MENU].loadFromFile("menu.png");
	m_background[MENU].setTexture(m_texture[MENU]);
	// set rectangle for the menu buttons and texts
	for (int row = 1; row < AmountOfWindows; row++)
	{
		m_menuRects[row - 1] = sf::RectangleShape({ 220, 120 });
		m_menuRects[row - 1].setFillColor(sf::Color(0, 0, 0, 3));
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
	m_texture[HELP].loadFromFile("help.png");
	m_background[HELP].setTexture(m_texture[HELP]);
	// set rectangle for the help back button
	m_helpRect = sf::RectangleShape({ 160, 90 });
	m_helpRect.setFillColor(sf::Color(0, 0, 0, 3));
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
	}
}
//_______________________________________________
void Window::drawWindow(sf::RenderWindow& window)const
{
	if (m_currentWindow[MENU])
		this->drawMenu(window);
	else if (m_currentWindow[HELP])
		this->drawHelp(window);
}
//___________________________________________________
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
//___________________________________________________
void Window::drawHelp(sf::RenderWindow& window)const
{
	window.clear();
	window.draw(m_background[HELP]);
	window.draw(m_helpRect);
	window.draw(m_helpText);
	window.display();
}
//__________________________
bool Window::isPlaying()const
{
	return m_currentWindow[PLAY];
}
//________________________
bool Window::isExit()const
{
	return m_currentWindow[EXIT];
}