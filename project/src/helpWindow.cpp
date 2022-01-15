#include "helpWindow.hpp"

//______________
HelpWindow::HelpWindow()
{
	setHelp();
}
//____________________
void HelpWindow::setHelp()
{
	// set back string text
	m_helpText.setFont(Resources::instance().getFont());
	m_helpText.setCharacterSize(80);
	m_helpText.setFillColor(sf::Color::White);
	m_helpText.setPosition(sf::Vector2f(25, 20));
	m_helpText.setString("BACK");
}
//_________________________________________________________
void HelpWindow::checkHelpPressed(const sf::Vector2f &location)
{
	if (m_helpText.getGlobalBounds().contains(location))
	{
		m_currentWindow[HELP] = false;
		m_currentWindow[MENU] = true;
		Resources::instance().playSound(ClickSound);
	}
}
//___________________________________________________
void HelpWindow::drawHelp(sf::RenderWindow &window) const
{
	window.clear();
	window.draw(Resources::instance().getSprite(HelpScreen));
	window.draw(m_helpText);
	window.display();
}