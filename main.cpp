#include <SFML/Graphics.hpp>  // Include the SFML graphics module for drawing
#include <iostream>  // Include iostream for printing error messages

int main()
{
    // Create a window with a resolution of 640x480 pixels and a title "Sprite rendering"
    sf::RenderWindow window(sf::VideoMode({640, 480}), "Sprite rendering");

    // Create an sf::Image object to hold the image data
    sf::Image heroimage;
    
    // Try to load the image from the file. If it fails, print an error message and exit.
    if (!heroimage.loadFromFile("images/Walk.png"))
    {
        std::cerr << "Error loading image!" << std::endl;  // Output error message to the console
        return -1;  // Return with an error code (-1) if image fails to load
    }

    // Create an sf::Texture object to store the texture data (which is derived from the image)
    sf::Texture herotexture;
    
    // Try to load the texture from the image. If it fails, print an error message and exit.
    if (!herotexture.loadFromImage(heroimage))
    {
        std::cerr << "Error loading texture from image!" << std::endl;  // Output error message to the console
        return -1;  // Return with an error code (-1) if texture fails to load
    }

    // Create an sf::Sprite object to represent the hero character in the game. It uses the texture we just loaded.
    sf::Sprite herosprite(herotexture);

    herosprite.setTextureRect(sf::IntRect({0, 0}, {32, 32}));
    // Set the initial position of the sprite (32px from the left, 32px from the top of the window)
    herosprite.setPosition({50.f, 25.f});
    herosprite.scale({3.f, 3.f});

    // Main loop: keep the window open and handle events until it's closed
    while (window.isOpen())
    {
        // Event handling: check for events like window closing
        while (std::optional<sf::Event> event = window.pollEvent())
        {
            // If the window close event is triggered, close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Clear the window (reset it to a blank state before drawing the next frame)
        window.clear();
        
        // Draw the sprite (the hero) onto the window
        window.draw(herosprite);
        
        // Display the window (show the content we've drawn so far)
        window.display();
    }

    // Return 0 to indicate the program ended successfully
    return 0;
}
