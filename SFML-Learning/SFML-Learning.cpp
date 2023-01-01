#include <SFML/Graphics.hpp>



class Game {
private:
    sf::RenderWindow m_window;
    sf::CircleShape m_player;
    //sf::RenderWindow::setVerticalSyncEnabled();// вкл или выкл V-Sync
    float PlayerSpeed = 100.f;
    sf::Time TimePerFrame = sf::seconds(1.f / 144.f);
    bool mIsMovingUp = false, mIsMovingDown = false, mIsMovingLeft = false, mIsMovingRight = false;
public:
    Game(size_t width, size_t heigth, char* name) : m_window(sf::VideoMode(width, heigth), name), m_player() {
        m_player.setFillColor(sf::Color::Cyan);
        m_player.setRadius(10.f);
        m_player.setPosition(100.f,100.f);
    }
    void run() {
        sf::Clock clock;
        sf::Time timeSinceLastUpdate = sf::Time::Zero;
        while (m_window.isOpen()) {
            timeSinceLastUpdate += clock.restart(); 
            while (timeSinceLastUpdate > TimePerFrame) {
                timeSinceLastUpdate -= TimePerFrame;
                processEvents();
                update(TimePerFrame);
            }
            render();
        }
    }
private:
    void update(sf::Time deltaTime) {
        sf::Vector2f movement(0.f, 0.f);
        if (mIsMovingUp)
            movement.y -= PlayerSpeed;
        if (mIsMovingDown)
            movement.y += PlayerSpeed;
        if (mIsMovingLeft)
            movement.x -= PlayerSpeed;
        if (mIsMovingRight)
            movement.x += PlayerSpeed;
        m_player.move(movement * deltaTime.asSeconds());
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