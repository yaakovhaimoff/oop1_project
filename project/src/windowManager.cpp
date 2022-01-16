#include "windowManager.hpp"

//___________________________
WindowManager::WindowManager()
{
    Resources::instance().playInLoop(menuSound);
}
//__________________________________________________________________________________
void WindowManager::catchMouseEvent(sf::RenderWindow &window, const sf::Event &event)
{
    if (m_currentWindow[MENU])
        m_menuWindow.checkMouseOnMenu(event);
    else if (m_currentWindow[HELP])
        m_helpWindow.checkMouseOnBack(event);
    else if (m_currentWindow[SELECT])
        m_selectLevel.checkMouseOnLevelSelect(event);
}
//___________________________________________________________________
void WindowManager::handleClickInWindow(const sf::Vector2f &location)
{
    if (m_currentWindow[MENU])
        m_menuWindow.checkMenuPressed(location, *this);
    else if (m_currentWindow[HELP])
        m_helpWindow.checkHelpPressed(location, *this);
    else if (m_currentWindow[PLAY])
        m_playWindow.checkPlayPressed(location);
    else if (m_currentWindow[SELECT])
        m_selectLevel.checkLevelPressed(location, *this);
}
//____________________________________________________________
void WindowManager::drawWindow(sf::RenderWindow &window) const
{
    if (m_currentWindow[MENU])
        m_menuWindow.drawMenu(window);
    else if (m_currentWindow[HELP])
        m_helpWindow.drawHelp(window);
    else if (m_currentWindow[SELECT])
        m_selectLevel.drawSelectLevel(window);
}
//________________________________
bool WindowManager::isExit() const
{
    return m_currentWindow[EXIT];
}
//___________________________________________________________
void WindowManager::setWindow(const int curr, const int prev)
{
    m_currentWindow[curr] = true;
    m_currentWindow[prev] = false;
}
//___________________________________________________________
void WindowManager::winLevelMessage(sf::RenderWindow &window) const
{
    m_playWindow.winLevelMessage(window);
}
//________________________________________________________________
void WindowManager::gameOverLevelMessage(sf::RenderWindow &window) const
{
    m_playWindow.gameOverLevelMessage(window);
}
//____________________________________________________________
void WindowManager::drawPauseMessage(sf::RenderWindow &window) const
{
    m_playWindow.drawPauseMessage(window);
}
//_______________________________________________________________________________________________
void WindowManager::drawPlayWindow(sf::RenderWindow &window, const int &time, const int level, const bool key,
							const int player) const
{
    m_playWindow.drawPlayWindow(window, time, level, key, player);
}
//___________________________________
bool WindowManager::isPlaying() const
{
    return m_currentWindow[PLAY];
}
//_________________________________
bool WindowManager::isPause() const
{
	return m_playWindow.isPause();
}