#include <console-game.hpp>

GameObject::GameObject(float startX, float startY, sf::RenderWindow& window) : m_window(window)
{
    position.x = startX;
    position.y = startY;
    speed = 5.0f;
}
