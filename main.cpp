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
