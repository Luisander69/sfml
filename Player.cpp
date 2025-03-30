#include "Player.h"
#include <iostream>

Player::Player() : currentFrame(0), sprite(texture) // Ініціалізація sprite через texture
{
    if (!texture.loadFromFile("images/Walk.png"))
    {
        std::cerr << "Error loading texture!" << std::endl;
    }

    sprite.setTexture(texture); // Прив'язуємо текстуру до спрайта
    sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)));
    sprite.setPosition(sf::Vector2f(32.f, 32.f)); // Початкове положення гравця
}

void Player::handleInput(float deltaTime)
{

    float speed = deltaTime; // Обчислюємо швидкість руху гравця
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        currentFrame += 0.005f * speed;
        if (currentFrame > 3) currentFrame -= 3;
        sprite.move(sf::Vector2f(-speed/8, 0.f));
        sprite.setTextureRect(sf::IntRect(sf::Vector2i(32 * int(currentFrame), 96), sf::Vector2i(32, 32)));
               
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        currentFrame += 0.005f * speed;
        if (currentFrame > 3) currentFrame -= 3;
        sprite.move(sf::Vector2f(speed/8, 0.f));
        sprite.setTextureRect(sf::IntRect(sf::Vector2i(32 * int(currentFrame), 64), sf::Vector2i(32, 32)));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        currentFrame += 0.005f * speed;
        if (currentFrame > 3) currentFrame -= 3;
        sprite.move(sf::Vector2f(0.f, -speed/8));
        sprite.setTextureRect(sf::IntRect(sf::Vector2i(32 * int(currentFrame), 32), sf::Vector2i(32, 32)));

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        currentFrame += 0.005f * speed;
        if (currentFrame > 3) currentFrame -= 3;
        sprite.move(sf::Vector2f(0.f, speed/8));
        sprite.setTextureRect(sf::IntRect(sf::Vector2i(32 * int(currentFrame),  0), sf::Vector2i(32, 32)));
    }
}

sf::Sprite& Player::getSprite()
{
    return sprite;
}
