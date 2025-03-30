#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

int main()
{
    // Створення вікна розміром 640x480 пікселів
    sf::RenderWindow window(sf::VideoMode({640, 480}), "Рух спрайта");

    // Завантаження текстури персонажа з файлу
    sf::Texture herotexture;
    if (!herotexture.loadFromFile("images/Walk.png"))
        return -1; // Якщо завантаження не вдалося, повертаємо -1

    // Створення спрайта та встановлення йому текстури
    sf::Sprite herosprite(herotexture);
    herosprite.setPosition({32.f, 32.f}); // Встановлення початкової позиції спрайта
    herosprite.setTextureRect(sf::IntRect({0, 0}, {32, 32})); // Визначення області текстури для спрайта

    float CurrentFrame = 0; // Поточний кадр анімації
    sf::Clock clock; // Годинник для відстеження часу між кадрами

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds(); // Отримуємо час у мікросекундах
        clock.restart(); // Перезапускаємо годинник
        time = time / 800; // Зменшуємо значення для корекції швидкості

        // Обробка подій у вікні
        while (std::optional<sf::Event> event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close(); // Закриваємо вікно, якщо отримано подію закриття
        }

        std::cout << CurrentFrame << "\n"; // Вивід значення поточного кадру в консоль

        // Перевірка натискання клавіш та оновлення позиції спрайта
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            herosprite.move(sf::Vector2f(-0.1f * time, 0.f)); // Рух ліворуч
            herosprite.setTextureRect(sf::IntRect({32 * int(CurrentFrame), 96}, {32, 32})); // Анімація для руху вліво
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            herosprite.move(sf::Vector2f(0.1f * time, 0.f)); // Рух праворуч
            herosprite.setTextureRect(sf::IntRect({32 * int(CurrentFrame), 64}, {32, 32})); // Анімація для руху вправо
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            herosprite.move(sf::Vector2f(0.f, -0.1f * time)); // Рух вгору
            herosprite.setTextureRect(sf::IntRect({32 * int(CurrentFrame), 32}, {32, 32})); // Анімація для руху вгору
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            herosprite.move(sf::Vector2f(0.f, 0.1f * time)); // Рух вниз
            herosprite.setTextureRect(sf::IntRect({32 * int(CurrentFrame), 0}, {32, 32})); // Анімація для руху вниз
        }

        window.clear(); // Очищаємо вікно перед відображенням нового кадру
        window.draw(herosprite); // Малюємо спрайт на екрані
        window.display(); // Відображаємо новий кадр
    }

    return 0;
}


/*// Game.h - Оголошення класу Game
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class Game {
public:
    Game(); // Конструктор гри
    void run(); // Основний ігровий цикл

private:
    void processEvents(); // Обробка подій (натискання клавіш, закриття вікна)
    void update(float deltaTime); // Оновлення стану гри (переміщення гравця)
    void render(); // Малювання об'єктів на екрані

    sf::RenderWindow window; // Вікно для відображення гри
    Player player; // Гравець (спрайт, рух, анімація)
};

#endif

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
        float deltaTime = clock.restart().asSeconds(); // Отримуємо час між кадрами
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

// Player.h - Оголошення класу Player
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(); // Конструктор гравця
    void handleInput(float deltaTime); // Обробка введення (натискання клавіш)
    sf::Sprite getSprite() const; // Отримати спрайт гравця

private:
    sf::Texture texture; // Текстура гравця
    sf::Sprite sprite; // Спрайт гравця
    float currentFrame; // Поточний кадр анімації
};

#endif

// Player.cpp - Реалізація класу Player
#include "Player.h"
#include <iostream>

Player::Player() : currentFrame(0)
{
    if (!texture.loadFromFile("images/Walk.png"))
    {
        std::cerr << "Error loading texture!" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect({0, 0}, {32, 32})); // Встановлюємо область текстури
    sprite.setPosition({32.f, 32.f}); // Початкове положення гравця
}

void Player::handleInput(float deltaTime)
{
    float speed = 100.f * deltaTime; // Обчислюємо швидкість руху гравця
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        currentFrame += 0.005f * speed;
        if (currentFrame > 3) currentFrame -= 3;
        sprite.move(-speed, 0.f);
        sprite.setTextureRect(sf::IntRect({32 * int(currentFrame), 96}, {32, 32}));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        currentFrame += 0.005f * speed;
        if (currentFrame > 3) currentFrame -= 3;
        sprite.move(speed, 0.f);
        sprite.setTextureRect(sf::IntRect({32 * int(currentFrame), 64}, {32, 32}));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        currentFrame += 0.005f * speed;
        if (currentFrame > 3) currentFrame -= 3;
        sprite.move(0.f, -speed);
        sprite.setTextureRect(sf::IntRect({32 * int(currentFrame), 32}, {32, 32}));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        currentFrame += 0.005f * speed;
        if (currentFrame > 3) currentFrame -= 3;
        sprite.move(0.f, speed);
        sprite.setTextureRect(sf::IntRect({32 * int(currentFrame), 0}, {32, 32}));
    }
}

sf::Sprite Player::getSprite() const
{
    return sprite;
}

// main.cpp - Головна функція для запуску гри
#include "Game.h"

int main()
{
    Game game;
    game.run(); // Запуск гри
    return 0;
}
*/
