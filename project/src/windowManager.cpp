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
        checkMouseOnMenu(event);
    else if (m_currentWindow[HELP])
        checkMouseOnBack(event);
    else if (m_levelSelect)
        checkMouseOnLevelSelect(event);
}
//___________________________________________________
void WindowManager::checkMouseOnBack(const sf::Event &event)
{
    auto location = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
    if (m_helpText.getGlobalBounds().contains(location))
        m_helpText.setFillColor(sf::Color::Black);
    else
        m_helpText.setFillColor(sf::Color::White);
}

//___________________________________________________________
void WindowManager::handleClickInWindow(const sf::Vector2f &location)
{
    if (m_currentWindow[MENU])
        checkMenuPressed(location);
    else if (m_currentWindow[HELP])
        checkHelpPressed(location);
    else if (m_currentWindow[PLAY])
        checkPlayPressed(location);
    else if (m_levelSelect)
        checkLevelPressed(location);
}

//____________________________________________________
void WindowManager::drawWindow(sf::RenderWindow &window) const
{
    if (m_currentWindow[MENU])
        drawMenu(window);
    else if (m_currentWindow[HELP])
        drawHelp(window);
    else if (m_levelSelect)
        drawSelectLevel(window);
}
//________________________________
bool WindowManager::isExit() const
{
    return m_currentWindow[EXIT];
}
//_________________________________________________________________________
void WindowManager::setWindow(const bool currWindow, const bool prevWindow,
                              const int curr, const int prev)
{
    m_currentWindow[curr] = currWindow;
    m_currentWindow[prev] = prevWindow;
}