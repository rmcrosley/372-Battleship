//  Rachel Crosley & Daniel Lind
//  battleship2.0.cpp
//  Battleship2.0
//  2/19/18


#include <iostream>
#include <SFML/Graphics.hpp>


int main() {
    
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Battle Time");
    
    while(window.isOpen()) {
        sf::Event event;
        //handle all events
        while(window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                default:
                    break;
            }
        }
        //update game
        window.clear();
        //draw objects here
        //draw background image
        sf::Texture texture;
        if(!texture.loadFromFile("/Users/rachelcrosley/Documents/Software Construction/Battleship3.0/Battleship3.0/Textures/GameBackDrop.jpg")) {
        }
        sf::Sprite background(texture);
        window.draw(background);
        
        
        
        window.display();
    }
    
    
    
    return 0;
}
