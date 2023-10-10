#include <console-game.hpp>

int main() {
    const unsigned int windowWidth = 800;
    const unsigned int windowHeight = 600;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Pong!", sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    std::unique_ptr<Pong> game = std::make_unique<Pong>(window, windowWidth, windowHeight);

    game->Run();
    return 0;
}
