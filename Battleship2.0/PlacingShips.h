//
//  PlacingShips.h
//  Battleship3.0
//
//  Created by Rachel Crosley on 2/28/18.
//  Copyright © 2018 Rachel Crosley. All rights reserved.
//

#ifndef PlacingShips_h
#define PlacingShips_h



pair<int, int> randomBoats();
void placeShipsOnBoard_comp();
vector<sf::RectangleShape> placeShipsOnBoard_user(const vector<Ships*> & fleet);
vector<sf::RectangleShape> updateShipsOnBoard_user(const vector<Ships*> & fleet, vector<sf::RectangleShape> & shapes);
pair<size_t, size_t> getMousePosition(sf::Vector2i mousePos, bool shipsNotYetPlaced);












#endif /* PlacingShips_h */
