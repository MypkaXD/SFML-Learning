#include <SFML/Graphics.hpp>

class Game {
private:
    sf::RenderWindow m_window;
    sf::CircleShape m_player;
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

    }
    void render() {
        m_window.clear();
        m_window.draw(m_player);
        m_window.display();
    }
    void processEvents() {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }
    }
};


int main()
{
    Game game(1920,1080,"CRINGE");
    game.run();

    return 0;
}