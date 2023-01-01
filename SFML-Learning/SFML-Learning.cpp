#include <SFML/Graphics.hpp>



class Game {
private:
    sf::RenderWindow m_window;
    sf::CircleShape m_player;
    bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;
public:
    Game(size_t width, size_t heigth, char* name) : m_window(sf::VideoMode(width, heigth), name), m_player() {
        m_player.setFillColor(sf::Color::Cyan);
        m_player.setRadius(10.f);
    }
    void run() {
        while (m_window.isOpen()) {
            processEvents();
            update();
            render();
        }
    }
private:
    void update() {
        sf::Vector2f movement(0.f, 0.f);
        if (mIsMovingUp)
            movement.y -= 0.1f;
        if (mIsMovingDown)
            movement.y += 0.1f;
        if (mIsMovingLeft)
            movement.x -= 0.1f;
        if (mIsMovingRight)
            movement.x += 0.1f;
        m_player.move(movement);
    }
    void render() {
        m_window.clear();
        m_window.draw(m_player);
        m_window.display();
    }
    void processEvents() {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            switch (event.type)
            {
            case sf::Event::KeyPressed:// клавиша нажата
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased: // клавиша отпущена
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                m_window.close();
                break;
            default:
                break;
            }
        }
    }
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
        switch (key)
        {
        case sf::Keyboard::W:
            mIsMovingUp = isPressed;
            break;
        case sf::Keyboard::A:
            mIsMovingLeft = isPressed;
            break;
        case sf::Keyboard::S:
            mIsMovingDown = isPressed;
            break;
        case sf::Keyboard::D:
            mIsMovingRight = isPressed;
            break;
        default:
            break;
        }
    }
};


int main()
{
    Game game(1920,1080,"CRINGE");
    game.run();

    return 0;
}