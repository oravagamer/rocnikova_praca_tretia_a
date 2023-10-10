#include <console-game.hpp>

Ball::Ball(float startX, float startY, sf::RenderWindow& window) : GameObject(
        startX,
        startY,
        window) {
    ballShape.setRadius(radius);
    ballShape.setPosition(position);

    do {
        ballAngle = (std::rand() % 360) * 2 * pi / 360;
    } while (std::abs(std::cos(ballAngle)) < 0.7f);
}

sf::FloatRect Ball::getPosition() {
    return ballShape.getGlobalBounds();
}

sf::CircleShape Ball::getShape() {
    return ballShape;
}

float Ball::getRadius() {
    return radius;
}

void Ball::reboundTop() {
    ballAngle = -ballAngle;
    ballShape.setPosition(
            ballShape.getPosition().x,
            radius + 0.1f);
}

void Ball::reboundBottom() {
    ballAngle = -ballAngle;
    ballShape.setPosition(
            ballShape.getPosition().x,
            m_window.getSize().y - radius - 0.1f);
}

void Ball::reboundBat() {

}

void Ball::Update() {
    ballShape.move(
            std::cos(ballAngle) * (speed - 0.1),
            std::sin(ballAngle) * (speed - 0.1));
}

void Ball::Draw() {
    m_window.draw(ballShape);
}
