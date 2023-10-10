#ifndef CONSOLE_PONG_GAME_GAMEOBJECT_HPP
#define CONSOLE_PONG_GAME_GAMEOBJECT_HPP

#include <console-game.hpp>

class GameObject {
protected:
    sf::Vector2f position;
    float speed;
    sf::RenderWindow& m_window;

public:
    GameObject(float startX, float startY, sf::RenderWindow& window);
    virtual void Draw() = 0;
    virtual void Update() = 0;
};


#endif
