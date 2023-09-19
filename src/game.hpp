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
    
    Player* player;
    
    
    //Private functions
    void initializeVariables();
    void initializeWindow();
    void initializePlayer();

    
public:
    //constructor
    Game();
    
    //destructor
    virtual ~Game();
    
    //ACCESSORS
    const bool running()const;

    
    //FUNCTIONS
    void updatePlayer();
    void update();
    void renderPlayer();
    void render();
    
};

#endif /* game_hpp */
