//
//  Assets.hpp
//  Chess
//
//  Created by Václav Hlaváč on 25/01/2017.
//  Copyright © 2017 Václav Hlaváč. All rights reserved.
//

#ifndef Assets_hpp
#define Assets_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Assets {
public:
    Assets(void);
    sf::Sprite* getSprite(int);
    sf::Texture chessBoardTexture;
    sf::Texture piecesTexture;
    sf::Sprite chessBoardSprite;
    sf::Sprite pawnWhite;
    sf::Sprite pawnBlack;
    sf::Sprite knightWhite;
    sf::Sprite knightBlack;
    sf::Sprite bishopWhite;
    sf::Sprite bishopBlack;
    sf::Sprite rookWhite;
    sf::Sprite rookBlack;
    sf::Sprite queenWhite;
    sf::Sprite queenBlack;
    sf::Sprite kingWhite;
    sf::Sprite kingBlack;
    
};


#endif /* Assets_hpp */
