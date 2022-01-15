#include "SelectLevel.hpp"

//________________________
SelectLevel::SelectLevel()
{
    setSelectLevel();
}
//_____________________________
void SelectLevel::setIsLevelSelect()
{
	m_levelSelect = false;
	m_currentWindow[PLAY] = true;
}
//___________________________
void SelectLevel::setSelectLevel()
{
	// set rectangle for the Select Level buttons and texts
	for (int row = 0; row < AmountOfWindows; row++)
	{
		// set Texts
		m_selectLevelText[row].setFont(Resources::instance().getFont());
		m_selectLevelText[row].setCharacterSize(100);
		m_selectLevelText[row].setFillColor(sf::Color::White);
		m_selectLevelText[row].setPosition(sf::Vector2f(800, SPACE + 100 + (row * 200)));
		m_selectLevelText[row].setString(selectLevelNames[row]);
	}
	// set the game name
	m_selectLevelName.setFont(Resources::instance().getFont());
	m_selectLevelName.setCharacterSize(180);
	m_selectLevelName.setFillColor(sf::Color::Black);
	m_selectLevelName.setPosition(sf::Vector2f(520, 130));
	m_selectLevelName.setOutlineColor(sf::Color(0, 0, 0, 100));
	m_selectLevelName.setOutlineThickness(5);
	m_selectLevelName.setString("Select Level");
}
//__________________________________________________
void SelectLevel::drawSelectLevel(sf::RenderWindow &window) const
{
	window.clear();
	window.draw(Resources::instance().getSprite(SelecetLevel));
	window.draw(m_selectLevelName);
	for (int row = 0; row < LEVELS; row++)
		window.draw(m_selectLevelText[row]);
	window.display();
}
//__________________________________________________________
void SelectLevel::checkMouseOnLevelSelect(const sf::Event &event)
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
void SelectLevel::checkLevelPressed(const sf::Vector2f &location)
{
	auto levelSelectBottun = sf::RectangleShape({300, 130});

	for (int row = 0; row < LEVELS; row++)
	{
		levelSelectBottun.setPosition(m_selectLevelText[row].getPosition());
		if (levelSelectBottun.getGlobalBounds().contains(location))
		{
			m_levelSelected = row;
			Resources::instance().playSound(ClickSound);
			Resources::instance().playInLoop(GameSound);
			setIsLevelSelect();
			break;
		}
	}
}