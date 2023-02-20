#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>

#include "Screen.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 640), "Screen");
    sf::Image icon;
    ScreenType screenT = ScreenType::MENU;
    // window.setFramerateLimit();

    if (icon.loadFromFile("assets/icon.png"))
        window.setIcon(256, 256, icon.getPixelsPtr());

    Screen *screen = new MenuScreen();
    std::cout << "\n start";

    do
    {
        sf::Event event;
        screen->isEvent(window, event);
        if (screenT != screen->getScreen())
        {
            screenT = screen->getScreen();
            switch (screenT)
            {
            case ScreenType::MENU:
                screen = new MenuScreen();
                break;
            case ScreenType::GAME:
                screen = new GameScreen();
                break;
            }
        }
        window.clear(sf::Color(0, 0, 0, 0));
        screen->draw(window);
        window.display();
    } while (!screen->isEnd() && window.isOpen());

    std::cout << "\n end";

    return 0;
}