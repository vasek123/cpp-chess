//
//  Assets.cpp
//  Chess
//
//  Created by Václav Hlaváč on 25/01/2017.
//  Copyright © 2017 Václav Hlaváč. All rights reserved.
//

#include "Assets.hpp"

Assets::Assets() {
    pawnWhite.setTexture(piecesTexture);
    pawnWhite.setTextureRect(sf::IntRect(128 * 0, 128 * 1, 128, 128));
    
    pawnBlack.setTexture(piecesTexture);
    pawnBlack.setTextureRect(sf::IntRect(128 * 0, 128 * 0, 128, 128));
    
    knightWhite.setTexture(piecesTexture);
    knightWhite.setTextureRect(sf::IntRect(128 * 1, 128 * 1, 128, 128));
    
    knightBlack.setTexture(piecesTexture);
    knightBlack.setTextureRect(sf::IntRect(128 * 1, 128 * 0, 128, 128));
    
    bishopWhite.setTexture(piecesTexture);
    bishopWhite.setTextureRect(sf::IntRect(128 * 2, 128 * 1, 128, 128));
    
    bishopBlack.setTexture(piecesTexture);
    bishopBlack.setTextureRect(sf::IntRect(128 * 2, 128 * 0, 128, 128));
    
    rookWhite.setTexture(piecesTexture);
    rookWhite.setTextureRect(sf::IntRect(128 * 3, 128 * 1, 128, 128));
    
    rookBlack.setTexture(piecesTexture);
    rookBlack.setTextureRect(sf::IntRect(128 * 3, 128 * 0, 128, 128));
    
    queenWhite.setTexture(piecesTexture);
    queenWhite.setTextureRect(sf::IntRect(128 * 4, 128 * 1, 128, 128));
    
    queenBlack.setTexture(piecesTexture);
    queenBlack.setTextureRect(sf::IntRect(128 * 4, 128 * 0, 128, 128));
    
    kingWhite.setTexture(piecesTexture);
    kingWhite.setTextureRect(sf::IntRect(128 * 5, 128 * 1, 128, 128));
    
    kingBlack.setTexture(piecesTexture);
    kingBlack.setTextureRect(sf::IntRect(128 * 5, 128 * 0, 128, 128));
}

sf::Sprite* Assets::getSprite(int type) {
    if (type == 1) {
        return &pawnWhite;
    } else if (type == 11) {
        return &pawnBlack;
    } else if (type == 2) {
        return &knightWhite;
    } else if (type == 12) {
        return &knightBlack;
    } else if (type == 3) {
        return &bishopWhite;
    } else if (type == 13) {
        return &bishopBlack;
    } else if (type == 4) {
        return &rookWhite;
    } else if (type == 14) {
        return &rookBlack;
    } else if (type == 5) {
        return &queenWhite;
    } else if (type == 15) {
        return &queenBlack;
    } else if (type == 6) {
        return &kingWhite;
    } else if (type == 16) {
        return &kingBlack;
    }
}
