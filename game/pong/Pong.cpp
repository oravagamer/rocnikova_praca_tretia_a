#include <console-game.hpp>

Pong::Pong(sf::RenderWindow& window, const unsigned int& windowWidth, const unsigned int& windowHeight)
        : m_window(window), m_windowWidth(windowWidth), m_windowHeight(windowHeight) {
    RestartGame();

    font.loadFromFile("res/American Captain.ttf");
    gameOver.setFont(font);
    gameOver.setCharacterSize(42);
    gameOver.setFillColor(sf::Color::White);
    gameOver.setStyle(sf::Text::Bold);
    gameOver.setPosition((m_windowWidth / 2) - 100,
                         m_windowHeight / 2);

    pause.setFont(font);
    pause.setCharacterSize(42);
    pause.setFillColor(sf::Color::White);
    pause.setStyle(sf::Text::Regular);
    pause.setPosition((m_windowWidth / 2) - 80,
                      m_windowHeight / 2);

    restart.setFont(font);
    restart.setCharacterSize(25);
    restart.setFillColor(sf::Color::White);
    restart.setStyle(sf::Text::Regular);
    restart.setPosition((m_windowWidth / 2) - 100,
                        (m_windowHeight / 2) + 50);
}

sf::RenderWindow& Pong::GetWindow() {
    return m_window;
}

void Pong::RestartGame() {
    isPaused = false;
    isGameOver = false;
    isRestart = true;
    gameOver.setString("");
    pause.setString("");
    restart.setString("");
    player1 = std::make_unique<Paddle>(
            40,
            m_windowHeight / 2,
            m_window);
    player2 = std::make_unique<Paddle>(
            m_windowWidth - 50,
            m_windowHeight / 2,
            m_window);
    ball = std::make_unique<Ball>(
            m_windowWidth / 2,
            m_windowHeight / 2,
            m_window);
}

void Pong::HandleCollision() {
    if (ball->getShape().getPosition().x - ball->getRadius() < 0.0f) {
        isGameOver = true;
        gameOver.setString("PLAYER 2 WINS!");
        restart.setString("Press R to restart\nPress Esc to Quit");
    } else if (ball->getShape().getPosition().x + ball->getRadius() > m_windowWidth) {
        isGameOver = true;
        gameOver.setString("PLAYER 1 WINS!");
        restart.setString("Press R to restart\nPress Esc to Quit");
    } else if (ball->getShape().getPosition().y < 0.f) {
        ball->reboundTop();
    } else if (ball->getShape().getPosition().y + ball->getRadius() * 2 > m_windowHeight) {
        ball->reboundBottom();
    } else if (ball->getPosition().intersects(player2->getPosition())) {
        if (ball->getShape().getPosition().y > player2->getShape().getPosition().y)
            ball->ballAngle = ball->pi - ball->ballAngle + (std::rand() % 20) * ball->pi / 180;
        else
            ball->ballAngle = ball->pi - ball->ballAngle - (std::rand() % 20) * ball->pi / 180;

        ball->getShape().setPosition(
                player2->getShape().getPosition().x - ball->getRadius() - player2->getShape().getSize().x / 2 - 0.1f,
                ball->getShape().getPosition().y);
    } else if (ball->getPosition().intersects(player1->getPosition())) {
        if (ball->getShape().getPosition().y > player1->getShape().getPosition().y)
            ball->ballAngle = ball->pi - ball->ballAngle + (std::rand() % 20) * ball->pi / 180;
        else
            ball->ballAngle = ball->pi - ball->ballAngle - (std::rand() % 20) * ball->pi / 180;

        ball->getShape().setPosition(
                player1->getShape().getPosition().x - ball->getRadius() - player1->getShape().getSize().x / 2 - 0.1f,
                ball->getShape().getPosition().y);
    }
}

void Pong::HandleInput() {
    player1->HandleInput1();
    player2->HandleInput2();
}

void Pong::Update() {
    player1->Update();
    player2->Update();
    ball->Update();
}

void Pong::Draw() {
    player1->Draw();
    player2->Draw();
    ball->Draw();

    m_window.draw(pause);
    m_window.draw(gameOver);
    m_window.draw(restart);
}

void Pong::Run() {
    while (m_window.isOpen()) {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed or
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                m_window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
                if (!isGameOver)
                    isPaused = !isPaused;
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
                RestartGame();
        }

        m_window.clear();

        HandleCollision();

        if (!isPaused) {
            HandleInput();
            Update();
        }

        if (isPaused)
            pause.setString("Game Paused");
        else
            pause.setString("");

        Draw();

        m_window.display();
    }
}
