#include "windowInclude/helpWindow.hpp"
#include "windowInclude/windowManager.hpp"

//______________________
HelpWindow::HelpWindow()
{
	setHelp();
}
//________________________
void HelpWindow::setHelp()
{
	// set back string text
	m_helpText.setFont(Resources::instance().getFont());
	m_helpText.setCharacterSize(80);
	m_helpText.setFillColor(sf::Color::White);
	m_helpText.setPosition(sf::Vector2f(25, 20));
	m_helpText.setString("BACK");
}
//_____________________________________________________________________________________
void HelpWindow::checkHelpPressed(const sf::Vector2f &location, WindowManager& manager)
{
	if (m_helpText.getGlobalBounds().contains(location))
	{
		manager.setWindow(MENU, HELP);
		Resources::instance().playSound(ClickSound);
	}
}
//_______________________________________________________
void HelpWindow::checkMouseOnBack(const sf::Event &event)
{
    auto location = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
    if (m_helpText.getGlobalBounds().contains(location))
        m_helpText.setFillColor(sf::Color::Black);
    else
        m_helpText.setFillColor(sf::Color::White);
}

//___________________________________________________
void HelpWindow::drawHelp(sf::RenderWindow &window) const
{
	window.clear();
	window.draw(Resources::instance().getSprite(HelpScreen));
	window.draw(m_helpText);
	window.display();
}