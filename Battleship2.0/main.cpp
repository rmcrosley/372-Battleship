//  Rachel Crosley & Daniel Lind
//  main.cpp
//  Battleship2.0
//  2/21/18


#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <SFML/Graphics.hpp>
#include "GameBoard.h"
#include "battleship2.0.h"
#include "PlacingShips.h"
using std::vector;


int main() {
	size_t boardSize = 45 * 10;
	size_t nextBoard = 45 * 12;
    sf::RenderWindow window(sf::VideoMode(1035, 630), "Battle Time");
	sf::RectangleShape border(sf::Vector2f(10,630));
	sf::VertexArray outerBorder0(sf::LinesStrip, 5);
	sf::VertexArray outerBorder1(sf::LinesStrip, 5);
    sf::Sprite can;

	//set coordinates for outerBorder of left board
	outerBorder0[0].position = sf::Vector2f(45, 45);
	outerBorder0[1].position = sf::Vector2f(45+boardSize, 45);
	outerBorder0[2].position = sf::Vector2f(45+boardSize, 45+boardSize);
	outerBorder0[3].position = sf::Vector2f(45, 45+boardSize);
	outerBorder0[4].position = sf::Vector2f(45, 45);
	//set color for outerBorder of left board
	outerBorder0[0].color = sf::Color::Black;
	outerBorder0[1].color = sf::Color::Black;
	outerBorder0[2].color = sf::Color::Black;
	outerBorder0[3].color = sf::Color::Black;
	outerBorder0[4].color = sf::Color::Black;

	//set coordinates for outerBorder of right board
	outerBorder1[0].position = sf::Vector2f(nextBoard, 45);
	outerBorder1[1].position = sf::Vector2f(nextBoard + boardSize, 45);
	outerBorder1[2].position = sf::Vector2f(nextBoard + boardSize, 45 + boardSize);
	outerBorder1[3].position = sf::Vector2f(nextBoard, 45 + boardSize);
	outerBorder1[4].position = sf::Vector2f(nextBoard, 45);
	//set color for outerBorder of right board
	outerBorder1[0].color = sf::Color::Black;
	outerBorder1[1].color = sf::Color::Black;
	outerBorder1[2].color = sf::Color::Black;
	outerBorder1[3].color = sf::Color::Black;
	outerBorder1[4].color = sf::Color::Black;
    
	//grid for drawing the various tiles of our board
    //0=dark blue square 1=light blue square
    const int spots[] = {
        
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0,
        0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0,
		0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0,
		0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0,
		0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0,
		0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    
    GameMap map;
    if(!map.load("/Users/rachelcrosley/Documents/Software Construction/Battleship3.0/Battleship3.0/Textures/tileColors.png", sf::Vector2u (45, 45), spots, 23, 14)) {
        return -1;
    }
	//loads font from file in textures
	sf::Font font;
    if (!font.loadFromFile("/Users/rachelcrosley/Documents/Software Construction/Battleship3.0/Battleship3.0/Textures/ALGER.TTF"))
	{
		return -2;	//returns -2 if fails to load file. Usually fails because of incorrect file path
	}
    sf::Texture canoetext;
    if(!canoetext.loadFromFile("/Users/rachelcrosley/Documents/Software Construction/Battleship3.0/Battleship3.0/Textures/canoe.png")) {
        return -3;
    }
    
	//sets up the various texts
	sf::Text playerText;
	playerText.setFont(font);
	playerText.setString("PLAYER");
	playerText.setCharacterSize(45);
	playerText.setStyle(sf::Text::Bold);
	playerText.setPosition(135, 90 + boardSize);
	
	sf::Text enemyText;
	enemyText.setFont(font);
	enemyText.setString("ENEMY");
	enemyText.setCharacterSize(45);
	enemyText.setStyle(sf::Text::Bold);
	enemyText.setPosition(135+nextBoard, 90 + boardSize);
	sf::Text n0;
	sf::Text n1;
	sf::Text n2;
	sf::Text n3;
	sf::Text n4;
	sf::Text n5;
	sf::Text n6;
	sf::Text n7;
	sf::Text n8;
	sf::Text n9;
	//vectors for number text
	vector<sf::Text> numbersTop = { n0, n1, n2, n3, n4, n5, n6, n7, n8, n9 };
	vector<sf::Text> numbersSide = { n0, n1, n2, n3, n4, n5, n6, n7, n8, n9 };
	int count = 0;		
	for (auto &num : numbersTop)
	{
		num.setFont(font);
		num.setString(std::to_string(count));
		num.setCharacterSize(20);
		num.setPosition(nextBoard+22.5+(45*count), 23);
		num.setFillColor(sf::Color::Blue);
		++count;
	}
	count = 0;
	for (auto &num : numbersSide)
	{
		num.setFont(font);
		num.setString(std::to_string(count));
		num.setCharacterSize(20);
		num.setPosition(nextBoard-15, 55+(45*count));
		num.setFillColor(sf::Color::Blue);
		++count;
	}

	//transforming the mid border
	border.setPosition(513, 0);
	border.setFillColor(sf::Color::Red);
    
    
    
    
    
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
        
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if(mousePos.x >= 45 && mousePos.x <= 495) {
                if(mousePos.y >= 45 && mousePos.y <= 495) {
                    can.setTexture(canoetext);
                    can.setPosition((float) mousePos.x, (float)mousePos.y);
                }
            }
        }
        
        window.clear();
        window.draw(map);
		window.draw(outerBorder0);
		window.draw(outerBorder1);
		window.draw(playerText);
		window.draw(enemyText);
		for (auto &num : numbersTop)
		{
			window.draw(num);
		}
		for (auto &num : numbersSide)
		{
			window.draw(num);
		}
		window.draw(border);
        window.draw(can);
        window.display();
    }
    
    
    
    return 0;
}
