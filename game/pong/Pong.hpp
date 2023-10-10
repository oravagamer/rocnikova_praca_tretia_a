#ifndef ROCNIKOVA_PRACA_TRETIA_A_PONG_HPP
#define ROCNIKOVA_PRACA_TRETIA_A_PONG_HPP

#include <console-game.hpp>

class Pong {
private:
    std::unique_ptr<Paddle> player1;
    std::unique_ptr<Paddle> player2;
    std::unique_ptr<Ball> ball;

    sf::Font font;
    sf::Text pause;
    sf::Text gameOver;
    sf::Text restart;

    bool isPaused;
    bool isGameOver;
    bool isRestart;

public:
    sf::RenderWindow& m_window;
    const unsigned int m_windowWidth;
    const unsigned int m_windowHeight;
public:
    Pong(sf::RenderWindow& window, const unsigned int& windowWidth, const unsigned int& windowHeight);
    sf::RenderWindow& GetWindow();
    void RestartGame();
    void HandleCollision();
    void HandleInput();
    void Update();
    void Draw();
    void Run();
};


#endif
