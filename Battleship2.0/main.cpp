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
using std::cout;
using std::endl;

int main() {
	size_t boardSize = 45 * 10;
	size_t nextBoard = 45 * 12;
	sf::RenderWindow window(sf::VideoMode(1035, 630), "Battle Time");
	sf::RectangleShape border(sf::Vector2f(10, 630));
	sf::VertexArray outerBorder0(sf::LinesStrip, 5);
	sf::VertexArray outerBorder1(sf::LinesStrip, 5);

	//set coordinates for outerBorder of left board
	outerBorder0[0].position = sf::Vector2f(45, 45);
	outerBorder0[1].position = sf::Vector2f(45 + boardSize, 45);
	outerBorder0[2].position = sf::Vector2f(45 + boardSize, 45 + boardSize);
	outerBorder0[3].position = sf::Vector2f(45, 45 + boardSize);
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
	int spots[] = {
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
	if (!map.load("C:/Users/Overlord Dan/Documents/372-Battleship/Battleship2.0/Textures/tilesHitMiss.png", sf::Vector2u(45, 45), spots, 23, 14)) {
		return -1;
	}
	//loads font from file in textures
	sf::Font font;
	if (!font.loadFromFile("C:/Users/Overlord Dan/Documents/372-Battleship/Battleship2.0/Textures/ALGER.TTF"))
	{
		return -2;	//returns -2 if fails to load file. Usually fails because of incorrect file path
	}
	
	//construct ships
	Ships p1Tube(2);
	Ships p1Kayak(3);
	Ships p1Canoe(3);
	Ships p1Yacht(4);
	Ships p1Cruise(5);

	//create vector that takes pointers to the ships so no copies are created
	vector<Ships*> p1 = { &p1Tube, &p1Kayak, &p1Canoe, &p1Yacht, &p1Cruise };

	Ships p2Tube(2);
	Ships p2Kayak(3);
	Ships p2Canoe(3);
	Ships p2Yacht(4);
	Ships p2Cruise(5);

	vector<Ships*> p2 = { &p2Tube, &p2Kayak, &p2Canoe, &p2Yacht, &p2Cruise };
        for(auto & num : p2)
        {
            //num->updateCoordinates(randomBoats());
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
	enemyText.setPosition(135 + nextBoard, 90 + boardSize);
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
		num.setPosition(nextBoard + 22.5 + (45 * count), 23);
		num.setFillColor(sf::Color::Blue);
		++count;
	}
	count = 0;
	for (auto &num : numbersSide)
	{
		num.setFont(font);
		num.setString(std::to_string(count));
		num.setCharacterSize(20);
		num.setPosition(nextBoard - 15, 55 + (45 * count));
		num.setFillColor(sf::Color::Blue);
		++count;
	}

	sf::Texture tubeTexture;
	sf::Texture canoeTexture;
	sf::Texture kayakTexture;
	sf::Texture yachtTexture;
	sf::Texture cruiseTexture;


	if (!tubeTexture.loadFromFile("C:/Users/Overlord Dan/Documents/372-Battleship/Battleship2.0/Textures/innertube.png")) {
		return -3;
	}

	if (!canoeTexture.loadFromFile("C:/Users/Overlord Dan/Documents/372-Battleship/Battleship2.0/Textures/canoe.png")) {
		return -3;
	}

	if (!kayakTexture.loadFromFile("C:/Users/Overlord Dan/Documents/372-Battleship/Battleship2.0/Textures/kayak.png")) {
		return -3;
	}

	if (!yachtTexture.loadFromFile("C:/Users/Overlord Dan/Documents/372-Battleship/Battleship2.0/Textures/yacht.png")) {
		return -3;
	}

	if (!cruiseTexture.loadFromFile("C:/Users/Overlord Dan/Documents/372-Battleship/Battleship2.0/Textures/cruiseship.png")) {
		return -3;
	}

	//transforming the mid border
	border.setPosition(513, 0);
	border.setFillColor(sf::Color::Red);

	auto shipShapes=placeShipsOnBoard_user(p1);

	shipShapes[0].setTexture(&tubeTexture);
	shipShapes[1].setTexture(&canoeTexture);
	shipShapes[2].setTexture(&kayakTexture);
	shipShapes[3].setTexture(&yachtTexture);
	shipShapes[4].setTexture(&cruiseTexture);

	bool clicked = false;

	int first5 = 0;
    bool shipsNotYetPlaced = true;
	while (window.isOpen()) {
		sf::Event event;
		//handle all events
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                        shipsNotYetPlaced = false;
                    }
                    
                if (shipsNotYetPlaced == true ) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
                    {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        if(mousePos.y >= 45 && mousePos.y <= 495) {
                            if(mousePos.x >= 45 && mousePos.x <= 495) {
                                int m;
                                int n;
                                
                                m = mousePos.x % 45;
                                mousePos.x = mousePos.x - m;
                                
                                n = mousePos.y % 45;
                                mousePos.y = mousePos.y - n;
                                
                                auto s0 = std::make_pair(mousePos.x/45-1, mousePos.y/45-1);
                                p1[0]->updateCoordinates(s0);
                            }
                        }
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        if(mousePos.y >= 45 && mousePos.y <= 495) {
                            if(mousePos.x >= 45 && mousePos.x <= 495) {
                                int m;
                                int n;
                                
                                m = mousePos.x % 45;
                                mousePos.x = mousePos.x - m;
                                
                                n = mousePos.y % 45;
                                mousePos.y = mousePos.y - n;
                                
                                auto s1 = std::make_pair(mousePos.x/45-1, mousePos.y/45-1);
                                p1[1]->updateCoordinates(s1);
                            }
                        }
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        if(mousePos.y >= 45 && mousePos.y <= 495) {
                            if(mousePos.x >= 45 && mousePos.x <= 495) {
                                int m;
                                int n;
                                
                                m = mousePos.x % 45;
                                mousePos.x = mousePos.x - m;
                                
                                n = mousePos.y % 45;
                                mousePos.y = mousePos.y - n;
                                
                                auto s2 = std::make_pair(mousePos.x/45-1, mousePos.y/45-1);
                                p1[2]->updateCoordinates(s2);
                            }
                        }
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        if(mousePos.y >= 45 && mousePos.y <= 495) {
                            if(mousePos.x >= 45 && mousePos.x <= 495) {
                                int m;
                                int n;
                                
                                m = mousePos.x % 45;
                                mousePos.x = mousePos.x - m;
                                
                                n = mousePos.y % 45;
                                mousePos.y = mousePos.y - n;
                                
                                auto s3 = std::make_pair(mousePos.x/45-1, mousePos.y/45-1);
                                p1[3]->updateCoordinates(s3);
                            }
                        }
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        if(mousePos.y >= 45 && mousePos.y <= 495) {
                            if(mousePos.x >= 45 && mousePos.x <= 495) {
                                int m;
                                int n;
                                
                                m = mousePos.x % 45;
                                mousePos.x = mousePos.x - m;
                                
                                n = mousePos.y % 45;
                                mousePos.y = mousePos.y - n;
                                
                                auto s4 = std::make_pair(mousePos.x/45-1, mousePos.y/45-1);
                                p1[4]->updateCoordinates(s4);
                            }
                        }
                    }
                }
                    
                if (shipsNotYetPlaced == false) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if(mousePos.y >= 45 && mousePos.y <= 495) {
                            if(mousePos.x >= 540 && mousePos.x <= 990) {
                                int m;
                                int n;
                                
                                m = mousePos.x % 45;
                                mousePos.x = mousePos.x - m;
                                
                                n = mousePos.y % 45;
                                mousePos.y = mousePos.y - n;
                                int clicked_x=mousePos.x/45;
                                int clicked_y=mousePos.y/45;
                                auto shotCoordinate=std::make_pair(clicked_x-12, clicked_y-1);
                                for(auto num : p2)
                                {
                                    if(num->checkHit(shotCoordinate) == true)
                                    {
                                        spots[clicked_x+clicked_y*23]=2;
                                    }
                                }
                            }
                    }
                }
                    
                    
				break;
			default:
				break;
			}
		}
		window.clear();
                
                if (!map.load("C:/Users/Overlord Dan/Documents/372-Battleship/Battleship2.0/Textures/tilesHitMiss.png", sf::Vector2u(45, 45), spots, 23, 14)) {
		return -1;
                }
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
                updateShipsOnBoard_user(p1, shipShapes);
		shipShapes[0].setTexture(&tubeTexture);
		shipShapes[1].setTexture(&canoeTexture);
		shipShapes[2].setTexture(&kayakTexture);
		shipShapes[3].setTexture(&yachtTexture);
		shipShapes[4].setTexture(&cruiseTexture);
		for (auto &num : shipShapes)
		{
			window.draw(num);
		}
		window.draw(border);
		window.display();
	}
    
    
    return 0;
}
