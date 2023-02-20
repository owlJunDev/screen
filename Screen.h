#include "interface.cpp"

enum ScreenType {
    MENU,
    GAME,
    SETTING
};

class Screen {
protected:
    std::vector<Element *> elements;
    bool isEndProccess;
    bool isKeyPressed = false, isKeyFree = true;
    bool isMousePressed = false, isMouseFree = true;
    std::string enteredText = "";
    ScreenType screen;

    void defaultDraw(sf::RenderWindow &window);

public:

    virtual void draw(sf::RenderWindow &window) = 0;
    void isEvent(sf::RenderWindow &window, sf::Event event);
    virtual void key(sf::RenderWindow &window, sf::Event event) = 0;
    virtual void isLeftClick(sf::Vector2i mouse) = 0;

    ScreenType getScreen();
    bool isEnd();
    void textInput(sf::Event event);
};

class MenuScreen : public Screen {
    private:
    public:
    MenuScreen();
    ~MenuScreen();
    // void isEvent(sf::RenderWindow &window, sf::Event event) override;
    void draw(sf::RenderWindow &window) override;
    void key(sf::RenderWindow &window, sf::Event event) override;
    void isLeftClick(sf::Vector2i mouse) override;
};

class GameScreen : public Screen {
    private:
    public:
    GameScreen();
    ~GameScreen();
    // void isEvent(sf::RenderWindow &window, sf::Event event) override;
    void draw(sf::RenderWindow &window) override;
    void key(sf::RenderWindow &window, sf::Event event) override;
    void isLeftClick(sf::Vector2i mouse) override;
};