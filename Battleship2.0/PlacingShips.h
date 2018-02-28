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
void followMouse(const pair<size_t, size_t> & shipFront, sf::RectangleShape & shipSprite);
void dragAndDropUpdate(const pair<size_t, size_t> & shipFront, 
						sf::RectangleShape & ships, 
						Ships & ship);












#endif /* PlacingShips_h */
