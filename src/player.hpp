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
        void initiatePlayer1(float player);
        void initiatePlayer2(float player);

        void initiateVariable();
        sf::Sprite sprite;
        sf::Texture texture ;
        sf::Sprite sprite2;
        sf::Texture texture2;
        
        
        
        

    public:
        Player(float x = 0.f, float y = 0.f, float p = 0.f);
        ~Player();
        

        float movementSpeed;
        
        
        //Methods
        void updateMovement();
        void updateMovementPlayer2();

        void update();
        void updateP2();

        
            
        const bool checkCollision();
        
        void windowBoundaries();
        void windowBoundaries2();

        
            
        void kill();
        void killP2();

        //Access shape outside of private
        sf::Sprite& getShape();
        sf::Sprite& getShapeP2();


    void render(sf::RenderTarget* target);
        
        

        

};
#endif /* player_hpp */
