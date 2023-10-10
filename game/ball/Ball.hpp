#ifndef CONSOLE_PONG_GAME_BALL_HPP
#define CONSOLE_PONG_GAME_BALL_HPP

#include <console-game.hpp>

class Ball : public GameObject {
private:
    sf::CircleShape ballShape;
    const float radius = 10.0f;

public:
    float ballAngle = 0.0f;
    const float pi = 3.14159f;

public:
    Ball(float startX, float startY, sf::RenderWindow& window);
    sf::FloatRect getPosition();
    sf::CircleShape getShape();
    float getRadius();
    void reboundTop();
    void reboundBottom();
    void reboundBat();
    void Update() override;
    void Draw() override;
};


#endif
