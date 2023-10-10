#ifndef CONSOLE_PONG_GAME_PADDLE_HPP
#define CONSOLE_PONG_GAME_PADDLE_HPP

#include <console-game.hpp>

class Paddle : public GameObject {
private:
    sf::RectangleShape paddleShape;
    const int shapeWidth = 10;
    const int shapeHeight = 50;

public:
    Paddle(float startX, float startY, sf::RenderWindow& window);
    sf::FloatRect getPosition();
    sf::RectangleShape getShape();
    void moveUp();
    void moveDown();
    void HandleInput1();
    void HandleInput2();
    void Update() override;
    void Draw() override;
};

#endif
