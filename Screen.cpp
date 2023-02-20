#include "Screen.h"

/// Screen \\\|
void Screen::isEvent(sf::RenderWindow &window, sf::Event event)
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (isMouseFree)
            {
                isMouseFree = false;
                isMousePressed = true;
                isLeftClick(sf::Mouse::getPosition(window));
            }
        }
        if (event.type != sf::Event::MouseButtonPressed)
        {
            if (isMousePressed)
            {
                isMouseFree = true;
                isMousePressed = false;
            }
        }
        if (event.type == sf::Event::KeyPressed)
        {
            key(window, event);
        }
    }
}

ScreenType Screen::getScreen() { return screen; }
bool Screen::isEnd() { return isEndProccess; }

void Screen::defaultDraw(sf::RenderWindow &window)
{
    for (auto element : elements)
    {
        element->draw(window);
    }
}

/// MenuScreen \\\|

MenuScreen::MenuScreen()
{
    screen = ScreenType::MENU;
    elements.push_back(new Button(sf::Vector2f(150, 50), sf::Vector2f(10, 150), "play"));
}
void MenuScreen::draw(sf::RenderWindow &window) { defaultDraw(window); }
void MenuScreen::isLeftClick(sf::Vector2i mouse)
{
    if (elements.at(0)->isClick(mouse))
    {
        screen = ScreenType::GAME;
    }
}
void MenuScreen::key(sf::RenderWindow &window, sf::Event event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        isEndProccess = true;
    }
}

/// GameScreen \\\|

GameScreen::GameScreen()
{
    screen = ScreenType::GAME;
    elements.push_back(new Button(sf::Vector2f(150, 50), sf::Vector2f(0, 0), "back"));
}
void GameScreen::draw(sf::RenderWindow &window) { defaultDraw(window); }
void GameScreen::isLeftClick(sf::Vector2i mouse)
{
    if (elements.at(0)->isClick(mouse))
    {
        screen = ScreenType::MENU;
    }
}
void GameScreen::key(sf::RenderWindow &window, sf::Event event) {}

/*// Screen \\\|

Screen::Screen() {}
void Screen::draw(sf::RenderWindow &window) { defaultDraw(window); }
void Screen::isLeftClick(sf::Vector2i mouse) {}
void Screen::key(sf::RenderWindow &window, sf::Event event) {}
//*/