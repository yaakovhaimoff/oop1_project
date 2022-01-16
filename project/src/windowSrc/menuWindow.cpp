#include "windowInclude/menuWindow.hpp"
#include "windowInclude/windowManager.hpp"

//______________________
MenuWindow::MenuWindow()
{
	setMenu();
}
//________________________
void MenuWindow::setMenu()
{
	// set rectangle for the menu buttons and texts
	for (int row = 0; row < AmountOfWindows-1; row++)
	{
		m_menuText[row].setFont(Resources::instance().getFont());
		m_menuText[row].setCharacterSize(100);
		m_menuText[row].setFillColor(sf::Color::White);
		m_menuText[row].setPosition(sf::Vector2f((CELL + SPACE + 4) * (row + 1), SPACE+100));
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
//_______________________________________________________
void MenuWindow::checkMouseOnMenu(const sf::Event &event)
{
	auto location = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);

	for (int row = 0; row < AmountOfWindows-1; row++)
	{
		if (m_menuText[row].getGlobalBounds().contains(location))
		{
			m_menuText[row].setFillColor(sf::Color::Black);
			break;
		}
		else
			m_menuText[row].setFillColor(sf::Color::White);
	}
}
//_____________________________________________________________________________________
void MenuWindow::checkMenuPressed(const sf::Vector2f &location, WindowManager& manager)
{
	for (int row = 0; row < AmountOfWindows-1; row++)
	{
		if (m_menuText[row].getGlobalBounds().contains(location))
		{
			Resources::instance().playSound(ClickSound);
			if (row + 1 == PLAY)
				manager.setWindow(SELECT, MENU);
			else
				manager.setWindow(row + 1, MENU);
			break;
		}
	}
}
//_______________________________________________________
void MenuWindow::drawMenu(sf::RenderWindow &window) const
{
	window.clear();
	window.draw(Resources::instance().getSprite(MenuBackground));
	window.draw(m_gameName);
	for (int row = 0; row < AmountOfWindows-1; row++)
		window.draw(m_menuText[row]);

	window.display();
}