//  Rachel Crosley & Daniel Lind
//  battleship2.0.cpp
//  Battleship2.0
//  2/9/18


//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
#include "battleship2.0.h"
#include "ResourcePath.hpp"
#include "catch.hpp"
#include <map>
#include <utility>
#include <string>
#include<vector>
using std::vector;
using std::string;
using std::map;
using std::pair;

    //Ship constructor
    //default constructs them in top right corner of board horizontally
    //player should be able to drag and drop afterwards
    Ships(const int & length)   {      //constructor for Ships

    }
    //gets all of the coordinates of the ship
    //returns vector
    vector<pair<x, y> > getCoordinates()    {               //returns the coordinates of a ship

    }
    //gets the length of the boat
    size_t getLength() {                   //gets length of ship

    }
    //updates the coordinates of the boat by
    //moving through the vector of pairs
    //should be used for the drag and drop placement
    void updateCoordinates() {            //updates the coordinates of a ship

    }
    //checks if a fired shot has hit
    bool checkHit(pair<x, y> firedAt)    {   //checks if location fired at contains a ship

    }
    //checks if a chosen location is currently occupied by another
    //boat because stacking boats is BAD
    bool ifTaken(pair<x, y> placedAt)    {   //checks if user selected location is occupied by another ship

    }
int main() {
    return EXIT_SUCCESS;
}





