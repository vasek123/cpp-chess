#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ResourcePath.hpp"

#include <utility>
#include <math.h>
#include <iostream>
#include <Assets.hpp>

void drawPiece(sf::Sprite sprite, sf::RenderWindow& window, int x, int y) {
    sprite.setPosition(x * 128, y * 128);
    window.draw(sprite);
};

void move(std::pair<int, int> from, std::pair<int, int> to, int (&chessBoard)[8][8]) {
    chessBoard[to.second][to.first] = chessBoard[from.second][from.first];
    chessBoard[from.second][from.first] = 0;
}

void setChessBoardAt(std::pair<int, int> at, int type, int (&chessBoard)[8][8]) {
    chessBoard[at.second][at.first] = type;
}

void log(std::pair<int, int> from, std::pair<int, int> to) {
    char c[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    std::cout << c[from.first] << from.second << " " << c[to.first] << to.second << std::endl;
}

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "Chess");
    
    //Load the chess board texture
    sf::Texture chessBoardTexture;
    if (!chessBoardTexture.loadFromFile(resourcePath() + "chess_board.png")) {
        return EXIT_FAILURE;
    }
    
    //Load the pieces texture
    sf::Texture piecesTexture;
    if (!piecesTexture.loadFromFile(resourcePath() + "chess_pieces.png")) {
        return EXIT_FAILURE;
    }
    
    //Create the chess board sprite
    sf::Sprite chessBoardSprite;
    chessBoardSprite.setTexture(chessBoardTexture);
    
    //Load the textures...
    sf::Sprite pawnWhite;
    pawnWhite.setTexture(piecesTexture);
    pawnWhite.setTextureRect(sf::IntRect(128 * 0, 128 * 1, 128, 128));
    
    sf::Sprite pawnBlack;
    pawnBlack.setTexture(piecesTexture);
    pawnBlack.setTextureRect(sf::IntRect(128 * 0, 128 * 0, 128, 128));
    
    sf::Sprite knightWhite;
    knightWhite.setTexture(piecesTexture);
    knightWhite.setTextureRect(sf::IntRect(128 * 1, 128 * 1, 128, 128));
    
    sf::Sprite knightBlack;
    knightBlack.setTexture(piecesTexture);
    knightBlack.setTextureRect(sf::IntRect(128 * 1, 128 * 0, 128, 128));
    
    sf::Sprite bishopWhite;
    bishopWhite.setTexture(piecesTexture);
    bishopWhite.setTextureRect(sf::IntRect(128 * 2, 128 * 1, 128, 128));
    
    sf::Sprite bishopBlack;
    bishopBlack.setTexture(piecesTexture);
    bishopBlack.setTextureRect(sf::IntRect(128 * 2, 128 * 0, 128, 128));
    
    sf::Sprite rookWhite;
    rookWhite.setTexture(piecesTexture);
    rookWhite.setTextureRect(sf::IntRect(128 * 3, 128 * 1, 128, 128));
    
    sf::Sprite rookBlack;
    rookBlack.setTexture(piecesTexture);
    rookBlack.setTextureRect(sf::IntRect(128 * 3, 128 * 0, 128, 128));
    
    sf::Sprite queenWhite;
    queenWhite.setTexture(piecesTexture);
    queenWhite.setTextureRect(sf::IntRect(128 * 4, 128 * 1, 128, 128));
    
    sf::Sprite queenBlack;
    queenBlack.setTexture(piecesTexture);
    queenBlack.setTextureRect(sf::IntRect(128 * 4, 128 * 0, 128, 128));
    
    sf::Sprite kingWhite;
    kingWhite.setTexture(piecesTexture);
    kingWhite.setTextureRect(sf::IntRect(128 * 5, 128 * 1, 128, 128));
    
    sf::Sprite kingBlack;
    kingBlack.setTexture(piecesTexture);
    kingBlack.setTextureRect(sf::IntRect(128 * 5, 128 * 0, 128, 128));
    
    //Define the initial chess board
    int chessBoard[8][8] = {
        { 14, 12, 13, 15, 16, 13, 12, 14 },
        { 11, 11, 11, 11, 11, 11, 11, 11 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1, 1, 1, 1 },
        { 4, 2, 3, 5, 6, 3, 2, 4 }
    };
    
    
    //Global variables
    bool selected = false;
    int selectedType;
    sf::Sprite selectedSprite;
    int mouseX;
    int mouseY;
    int offsetX;
    int offsetY;
    std::pair<int, int> from;
    
    Assets assets;

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
            //Mouse left button click
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                
                int clickX = floor(event.mouseButton.x / 128);
                int clickY = floor(event.mouseButton.y / 128);
                
                int type = chessBoard[clickY][clickX];
                
                if (type != 0) {
                    
                    selected = true;
                    selectedType = type;
                    from = std::make_pair(clickX, clickY);
                    offsetX = (clickX * 128) - event.mouseButton.x;
                    offsetY = (clickY * 128) - event.mouseButton.y;
                    
                    if (type == 1) {
                        selectedSprite = pawnWhite;
                    } else if (type == 11) {
                        selectedSprite = pawnBlack;
                    } else if (type == 2) {
                        selectedSprite = knightWhite;
                    } else if (type == 12) {
                        selectedSprite = knightBlack;
                    } else if (type == 3) {
                        selectedSprite = bishopWhite;
                    } else if (type == 13) {
                        selectedSprite = bishopBlack;
                    } else if (type == 4) {
                        selectedSprite = rookWhite;
                    } else if (type == 14) {
                        selectedSprite = rookBlack;
                    } else if (type == 5) {
                        selectedSprite = queenWhite;
                    } else if (type == 15) {
                        selectedSprite = queenBlack;
                    } else if (type == 6) {
                        selectedSprite = kingWhite;
                    } else if (type == 16) {
                        selectedSprite = kingBlack;
                    }
                    
                    chessBoard[clickY][clickX] = 0;
                    
                }
            }
            
            //Mouse left button release
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && selected) {
                selected = false;
                int dropX = floor(event.mouseButton.x / 128);
                int dropY = floor(event.mouseButton.y / 128);
                setChessBoardAt(std::make_pair(dropX, dropY), selectedType, chessBoard);
                log(from, std::make_pair(dropX, dropY));
            }
            
            //Mouse move
            if (event.type == sf::Event::MouseMoved) {
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
            }
        }

        // Clear screen
        window.clear();
        
        //Draw the chess board
        window.draw(chessBoardSprite);
        
        //Draw the pieces
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++) {
                
                int value = chessBoard[y][x];
                
                if (value == 0) {
                    continue;
                } else if (value == 1 || value == 11) {
                    drawPiece((value == 1 ? pawnWhite : pawnBlack), window, x, y);
                } else if (value == 2 || value == 12) {
                    drawPiece((value == 2 ? knightWhite : knightBlack), window, x, y);
                } else if (value == 3 || value == 13) {
                    drawPiece((value == 3 ? bishopWhite : bishopBlack), window, x, y);
                } else if (value == 4 || value == 14) {
                    drawPiece((value == 4 ? rookWhite : rookBlack), window, x, y);
                } else if (value == 5 || value == 15) {
                    drawPiece((value == 5 ? queenWhite : queenBlack), window, x, y);
                } else if (value == 6 || value == 16) {
                    drawPiece((value == 6 ? kingWhite : kingBlack), window, x, y);
                }
                        
            }
        }
                           
        //And if selected, draw the moving piece
        if (selected) {
            selectedSprite.setPosition(mouseX + offsetX, mouseY + offsetY);
            window.draw(selectedSprite);
        }
        
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
