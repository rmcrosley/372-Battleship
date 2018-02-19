//  Rachel Crosley & Daniel Lind
//  battleship2.0.cpp
//  Battleship2.0
//  2/9/18


//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
#include "battleship2.0.h"
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
    size_t Ships::_count=0;
    Ships::Ships(const size_t & length)   {      //constructor for Ships
        _length=length;
        _orientation=0;
        for(size_t i=0; i<_length; ++i)
        {
            _coordinates.push_back(std::make_pair(i, _count));
        }
        _count++;
    }
    Ships::~Ships()    {
        _count--;
        _length=0;
        _coordinates.clear();
    }
    //gets all of the coordinates of the ship
    //returns vector
    vector<pair<x, y> > Ships::getCoordinates()    {               //returns the coordinates of a ship
        return _coordinates;
    }
    //gets the length of the boat
    size_t Ships::getLength() {                   //gets length of ship
        return _length;
    }
    bool Ships::getOrientation()   {
        return _orientation;
    }
    //updates the coordinates of the boat by
    //moving through the vector of pairs
    //should be used for the drag and drop placement
    //takes the coordinates for the very front of the ship and then
    //calculates the rest based off of front and orientation
    void Ships::updateCoordinates(pair<x, y> shipfront) {            //updates the coordinates of a ship
        _coordinates[0]=shipfront;
        x temp_x=shipfront.first;
        y temp_y=shipfront.second;
        if(_orientation==0) {       //orientation=0 is horizontal
            for(size_t i=1; i<_length; ++i)                //orientation=1 is vertical
            {
                ++temp_x;
                _coordinates[i].first=temp_x;
                _coordinates[i].second=shipfront.second;
            }
        } else  {
            for(size_t i=1; i<_length; ++i)
            {
                ++temp_y;
                _coordinates[i].second=temp_y;
                _coordinates[i].first=shipfront.first;
            }
        }
    }
    //updates the orientation of the boat(horizontal or vertical)
    //used to check if only the x or y coordinates
    //should be updated when user clicks button to change orientation
    void Ships::updateOrientation() {
        _orientation = !_orientation; 
    }
    //checks if a fired shot has hit
    bool Ships::checkHit(pair<x, y> firedAt)    {   //checks if location fired at contains a ship
        for(int i = 0; i < _coordinates.size(); ++i) {
            if(_coordinates[i] == firedAt) {
                return true;
            }
        }
        return false;
    }
    //checks if a chosen location is currently occupied by another
    //boat because stacking boats is BAD
    bool Ships::ifTaken(pair<x, y> placedAt)    {   //checks if user selected location is occupied by another ship
        return checkHit(placedAt);
    }





