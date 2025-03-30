#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(); // Конструктор
    void handleInput(float deltaTime); // Обробка введення
    sf::Sprite& getSprite(); // Отримати спрайт (повертає посилання)

private:
    sf::Texture texture; // Текстура гравця
    sf::Sprite sprite; // Спрайт гравця (повинен ініціалізуватися текстурою)
    float currentFrame; // Поточний кадр анімації
};

#endif
