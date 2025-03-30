// Game.h - Оголошення класу Game
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
