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
    bool endGame;
    
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
    sf::Text endGameText; 
    
    
    //walls
   // GameTile* tile;
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
    
    //end game
    const bool& getEndGame() const;
    
    
    //Methods
    const bool running()const;
    void updatePlayer();
    void update();
    void renderPlayer();
    void render();
    void spawnBalls();
    void spawnBadBalls();
    void updateCollision(sf::Sprite& playerSprite, unsigned int& score);
    
    
//    void PVPCollision(sf::Sprite& player1Sprite, sf::Sprite& player2Sprite, unsigned int& scoreP1, unsigned int& scoreP2);
    void PVPCollision(sf::Sprite& player1Sprite, sf::Sprite& player2Sprite, unsigned int& scoreP1, unsigned int& scoreP2);
    
    
    void initializeFont();
    void initializeText();
    void renderText(sf::RenderTarget* target);
    void updateText();
    void updateWallCollision(sf::Sprite& player1Sprite, sf::Sprite& player2Sprite, unsigned int& scoreP1, unsigned int& scoreP2);
    bool player1Wins(unsigned int& scoreP1);
    bool player2Wins(unsigned int& scoreP2);
    
    
    
    //TESTS
    //Get methods to test private variables
    
    int getPointsPlayer1() const {
        return pointsPlayer1;
    }
    
    int getPointsPlayer2() const {
        return pointsPlayer2;
    }
    
    float getSpawnTimerMax() const {
        return spawnTimerMax;
    }
    
    float getSpawnTimer() const {
        return spawnTimer;
    }
    
    int getMaxSpawnBalls() const {
        return maxSpawnBalls;
    }
    
    Player* getPlayer1() const {
        return player1;
    }
    
    Player* getPlayer2() const {
        return player2;
    }
    
    sf::RenderWindow* getWindow() {
        return window;
    }
    
    std::vector<GameTile*>& getMazeVec() {
        return mazeVec;
    }
    
};
    
#endif /* game_hpp */
