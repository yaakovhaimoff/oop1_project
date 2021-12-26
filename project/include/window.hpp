#include <stdio.h>
#include "macros.hpp"

class Window
{
public:
	Window();
	void manageWindow();
	void setTexture();
	void setBackground();
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
};
