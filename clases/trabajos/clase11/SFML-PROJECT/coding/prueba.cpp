#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <cstdlib>
 
int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(331, 293), "Mi Primer Programa Con SFML");
 
    // Load a sprite to display 
    sf::Texture texture;
    if (!texture.loadFromFile("cute_image.jpg")){
        system("echo NO se pudo cargar la textura&pause");
        return EXIT_FAILURE; 
    }    

    sf::Sprite sprite(texture);
 
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")){
        system("echo NO se pudo cargar la fuente&pause");
        return EXIT_FAILURE;
    }
    sf::Text text("Hello SFML", font, 50);
 
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("nice_music.ogg")){
        system("echo NO se pudo cargar la la musica&pause");
        return EXIT_FAILURE;
    }
 
    // Play the music
    music.play();
 
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
 
        // Clear screen
        window.clear();
 
        // Draw the sprite
        window.draw(sprite);
 
        // Draw the string
        window.draw(text);
 
        // Update the window
        window.display();
    }
 
    return EXIT_SUCCESS;
}