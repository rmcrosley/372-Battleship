//  Rachel Crosley and Daniel Lind
//  GameBoard.h
//  Battleship2.0
//  2/21/18

#ifndef GameBoard_h
#define GameBoard_h
#include <string>
using std::string;


class GameMap : public sf::Drawable, public sf::Transformable {
public:
    bool load(const string& gameBoardImage, sf::Vector2u tileSize, const int* tilesOnBoard, unsigned int width, unsigned int height) {
        
        if(!_gm.loadFromFile(gameBoardImage)) {
            return false;
        }
        _arr.setPrimitiveType(sf::Quads);
        _arr.resize(width * height * 4);
        
        for(int i = 0; i < width; ++i) {
            for(int j = 0; j < height; ++j) {
                int tileNum = tilesOnBoard[i + j * width];
                
				// find its position in the tileset texture
				int tu = tileNum % (_gm.getSize().x / tileSize.x);
				int tv = tileNum / (_gm.getSize().x / tileSize.x);

                sf::Vertex* quad = &_arr[(i + j * width) * 4];
                
                
                
                quad[0].position = sf::Vector2f(i * tileSize.x, j*tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

				// define its 4 texture coordinates
				quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
				quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
				quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
				quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
                
                
            }
        }
        
        return true;
    }
    
private:
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = &_gm;
        target.draw(_arr, states);
    }
    
    sf::VertexArray _arr;
    sf::Texture _gm;
};
















#endif /* GameBoard_h */
