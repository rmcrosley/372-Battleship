//  Rachel Crosley
//  battleship2.0.cpp
//  Battleship2.0
//  2/9/18


#ifndef battleship2_0_h
#define battleship2_0_h

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
using x=size_t;
using y=size_t;

class Ships {
public:
    static size_t _count;   //static variable for keeping track of amount of ships

    Ships(const size_t & length);      //constructor for Ships
    ~Ships();
    Ships(const Ships & boat)=delete;
    Ships & operator=(const Ships & boat)=delete;
    vector<pair<x, y> > getCoordinates();               //returns the coordinates of a ship
    size_t getLength();                    //gets length of ship
    void updateCoordinates(pair<x, y> shipfront);            //updates the coordinates of a ship
    void updateOrientation();               //updates the orientation of the ship(horizontal and vertical)
    bool checkHit(pair<x, y> firedAt);   //checks if location fired at contains a ship
    bool ifTaken(pair<x, y> placedAt);   //checks if user selected location is occupied by another ship

private:
    vector<pair<x, y> > _coordinates;
    size_t _length;
    bool _orientation;
};
















#endif /* battleship2_0_h */
