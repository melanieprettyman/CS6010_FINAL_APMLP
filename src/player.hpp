//
//  player.hpp
//  testSFML
//
//  Created by Melanie Prettyman on 9/19/23.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#pragma once


#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Player{

private:
    //player characteristics
    sf::RectangleShape shape;
    void initiateShape(sf::Color a);
    void initiateVariable();
    
    
    //player health
//    int hp;
//    int hpMax;

    
    
    

public:
    Player(float x = 0.f, float y = 0.f, sf::Color a = sf::Color::Green);
    ~Player();
    

    float movementSpeed;
    
    
    //Methods
    void updateMovement();
    void updateMovementPlayer2();

    void update();
    void updateP2();

    void render(sf::RenderTarget* target);
        
    const bool checkCollision();
    sf::RectangleShape& getShape();
    void windowBoundaries();
        
    void kill();

};
#endif /* player_hpp */
