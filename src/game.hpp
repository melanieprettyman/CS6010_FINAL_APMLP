//
//  game.hpp
//  testSFML
//
//  Created by Melanie Prettyman on 9/19/23.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include "player.hpp"
#include "pointsBall.hpp"
#include "tiles.hpp"


/*
 Class that acts as a the game engine
 Wrapper class
 */

class Game
{
    
private:

//VARIABLES
    //Window
    sf::RenderWindow* window; //window pointer
    sf::Event event;
    
    //Player
    Player* player1;
    Player* player2;

    //Point balls (swagBalls)
    std::vector<SwagBall> swagBalls;
    float spawnTimerMax;
    float spawnTimer;
    int maxSpawnBalls;
    
    
    //score
    unsigned int pointsPlayer1;
    unsigned int pointsPlayer2;
    
    //font and text variable for displaying points
    sf::Font font;
    sf::Text guiText;                   

    
    //walls
    GameTile* tile;
    std::vector<GameTile*> mazeVec;
    //function to set up tiles on maze
    void setUpTiles();
    
    
    //Private methods
    //window
    void initializeVariables(); 
    void initializeWindow();
    //player
    void initializePlayer();
    
    
public:
    //game constructor
    Game();
    
    //game destructor
    virtual ~Game();

    
    //Methods
    const bool running()const;
    void updatePlayer();
    void update();
    void renderPlayer();
    void render();
    void spawnBalls();
    void spawnBadBalls();
    void updateCollision(Player& player , unsigned int& score);
    void PVPCollision(Player& player1 , Player& player2, unsigned int& scoreP1, unsigned int& scoreP2);
    void initializeFont();
    void initializeText();
    void renderText(sf::RenderTarget* target);
    void updateText();


};
#endif /* game_hpp */
