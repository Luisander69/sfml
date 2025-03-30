// Game.cpp - Реалізація класу Game
#include "Game.h"

Game::Game() : window(sf::VideoMode({640, 480}), "Sprite Movement"), player()
{
    // Конструктор створює вікно гри та ініціалізує гравця
}

void Game::run()
{
    sf::Clock clock; // Годинник для підрахунку часу між кадрами
    while (window.isOpen())
    {
        float deltaTime = clock.getElapsedTime().asMicroseconds(); // Отримуємо час між кадрами
        clock.restart(); // Перезапускаємо годинник
        deltaTime = deltaTime / 800; // Зменшуємо значення для корекції швидкості
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents()
{
    while (std::optional<sf::Event> event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close(); // Закриваємо вікно при натисканні на хрестик
    }
}

void Game::update(float deltaTime)
{
    player.handleInput(deltaTime); // Викликаємо функцію обробки руху гравця
}

void Game::render()
{
    window.clear(); // Очищаємо екран
    window.draw(player.getSprite()); // Малюємо гравця
    window.display(); // Відображаємо кадр на екрані
}
