#include <stdio.h>
#include "macros.hpp"

class Window
{
public:
	Window();
	void manageWindow();
	void setTexture();
	void setBackground();
	void setMenu();
	void setHelp();
	void print();
	void printMenu();
	void printHelp();
	void printPlay();
	void handleClickInWindow(const sf::Vector2f&);
	void checkMenuPressed(const sf::Vector2f&);
	void checkHelpPressed(const sf::Vector2f&);

private:
	sf::RenderWindow m_window = { { 1920, 1080 }, "Save the king" };
	bool m_currentWindow[AmountOfWindows];
	sf::Texture m_texture[AmountOfWindows];
	sf::Sprite m_background[AmountOfWindows];
	sf::Font m_font;
	sf::Text m_gameName;

	sf::RectangleShape m_menuRects[AmountOfWindows-1];
	sf::Text m_menuText[AmountOfWindows-1];

	sf::RectangleShape m_helpRect;
	sf::Text m_helpText;
};
