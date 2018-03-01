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
	if (!map.load("C:/Users/Overlord Dan/Documents/372-Battleship/Battleship2.0/Textures/tileColors.png", sf::Vector2u(45, 45), spots, 23, 14)) {
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

	vector<Ships*> p2;
	p2.push_back(&p1Tube);
	p2.push_back(&p1Kayak);
	p2.push_back(&p1Canoe);
	p2.push_back(&p1Yacht);
	p2.push_back(&p1Cruise);


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
	while (window.isOpen()) {
		sf::Event event;
		//handle all events
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
				{
					cout << "Num1 hit" << endl;
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					auto m=getMousePosition(mousePos);
					while (true)
					{
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							m=getMousePosition(mousePos);
							cout << m.first <<", "<<m.second<< endl;
							p1[0]->updateCoordinates(getMousePosition(mousePos));
							break;
						}
					}
					
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
					cout << "Num2 hit" << endl;
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					auto m = getMousePosition(mousePos);
					while (true)
					{
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							m=getMousePosition(mousePos);
							cout << m.first << ", " << m.second << endl;
							p1[1]->updateCoordinates(getMousePosition(mousePos));
							break;
						}
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
					cout << "Num3 hit" << endl;
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					auto m = getMousePosition(mousePos);
					while (true)
					{
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							m=getMousePosition(mousePos);
							cout << m.first << ", " << m.second << endl;
							p1[2]->updateCoordinates(getMousePosition(mousePos));
							break;
						}
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
					cout << "Num4 hit" << endl;
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					auto m = getMousePosition(mousePos);
					while (true)
					{
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							m=getMousePosition(mousePos);
							cout << m.first << ", " << m.second << endl;
							p1[3]->updateCoordinates(getMousePosition(mousePos));
							break;
						}
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
					cout << "Num5 hit" << endl;
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					auto m = getMousePosition(mousePos);
					while (true)
					{
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							m=getMousePosition(mousePos);
							cout << m.first << ", " << m.second << endl;
							p1[4]->updateCoordinates(getMousePosition(mousePos));
							break;
						}
					}
				}
				break;
			default:
				break;
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
