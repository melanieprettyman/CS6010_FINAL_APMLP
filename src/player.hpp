//
//  player.hpp
//  testSFML
//
//  Created by Melanie Prettyman on 9/19/23.
//
#pragma once

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Player{

private:
    sf::RectangleShape shape; 
    void initiateShape(sf::Color a);
    void initiateVariable();
    
    
    //animation
    
    
    //movement
    
    //core
    
    
    float movementSpeed;
    
    
    

public:
    Player(float x = 0.f, float y = 0.f, sf::Color a = sf::Color::Green);
    ~Player();
    
//FUNCTIONS
void updateMovement();
void updateMovementPlayer2();

void update();
void updateP2();

void render(sf::RenderTarget* target);

};

#endif /* player_hpp */
