//  Rachel Crosley & Daniel Lind
//  battleship2.0.cpp
//  Battleship2.0
//  2/9/18


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "battleship2.0.h"
#include "ResourcePath.hpp"
#include "catch.hpp"
#include <map>
#include <utility>
#include <string>
using std::string;
using std::map;
using std::pair;



class Ships {
public:
    Ships(int col, int row, string name) {
        shipName = name;
        location.first = col;
        location.second = row;
    }
    
    
    
    
    
    
private:
    pair<int, int> location;
    string shipName;
};




int main() {
    
    map<string, pair<int, int>> shipComp;
    map<string, pair<int, int>> shipUser;
    
    
    
    

    return EXIT_SUCCESS;
}





