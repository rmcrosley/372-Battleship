//  Rachel Crosley and Daniel Lind
//  PlacingShips.cpp
//  Battleship2.0
//  2/27/18

#include <stdio.h>
#include "battleship2.0.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <utility>
using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;
using std::pair;




random_device rd;
mt19937 gen(rd());

pair<int, int> randomBoats() {
    pair<int, int> sf;
    int x;
    int y;

    uniform_int_distribution<int> distrib(1, 10);
    x = distrib(gen);
    y = distrib(gen);
    sf.first = x;
    sf.second = y;

    return sf;
}




void placeShipsOnBoard_comp() {
    int updown;

    Ships canoe(2);

    while (true) {
        pair<int, int> shipfront = randomBoats();

        if (canoe.ifTaken(shipfront) == false) {
            canoe.updateCoordinates(shipfront);
            break;
        }
    }


}

//default constructs the sprites for the ships based off of the constructor for Ships class
vector<sf::RectangleShape> placeShipsOnBoard_user(const vector<Ships*> & fleet) {
	sf::RectangleShape tube;
	sf::RectangleShape canoe;
	sf::RectangleShape kayak;
	sf::RectangleShape yacht;
	sf::RectangleShape cruise;
	vector<sf::RectangleShape> shapes = {tube, canoe, kayak, yacht, cruise};
	int count = 0;
	for (auto &num : shapes)
	{
		num.setSize(sf::Vector2f(45 * fleet[count]->getLength(), 40));
		num.setPosition(45, 47.5+45*fleet[count]->getCoordinates()[count].second);
		count++;
	}

	return shapes;
}

void followMouse(const pair<size_t, size_t> & shipFront, sf::RectangleShape & shipSprite) {
	shipSprite.setPosition(shipFront.first, shipFront.second);
}

void dragAndDropUpdate(const pair<size_t, size_t> & shipFront, 
						sf::RectangleShape & shipSprite, 
						Ships & ship)	{
	//updates the coordinates of the Ships object
	ship.updateCoordinates(shipFront);
	//then adjusts the sprite to the new position to be redrawn
	shipSprite.setPosition(shipFront.first, shipFront.second);
}


























