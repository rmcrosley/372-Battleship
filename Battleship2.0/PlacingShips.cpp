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


void placeShipsOnBoard_user(sf::Vector2i &mousePos) {
   
    Ships canoe(3);
    
    pair<int, int> shipfront;
    shipfront.first = mousePos.x;
    shipfront.second = mousePos.y;
    
    while (true) {
        if(canoe.ifTaken(shipfront) == false) {
            canoe.updateCoordinates(shipfront);
            break;
        }
    }
  
}


























