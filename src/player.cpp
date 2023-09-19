//
//  player.cpp
//  testSFML
//
//  Created by Melanie Prettyman on 9/19/23.
//

#include "player.hpp"

//Construtor
Player::Player(float x, float y, sf::Color a){
    this->shape.setPosition(x,y);
    this->initiateShape(a);
    this->initiateVariable();
}

//Destructor
Player::~Player(){
    
}



//~~~initiate Shape~~~
void Player::initiateShape(sf::Color a){
    this->shape.setFillColor(a);
    this->shape.setSize(sf::Vector2f(50.f,50.f));
}

//~~~initiate variable~~~
void Player::initiateVariable(){
    this->movementSpeed=10.f;
}


//Functions

//~~~update~~~
void Player::update(){
    
    
    //Detecting keybord input and moving the player with that input
    this->updateMovement();
    
    
    
}



//~~~update movement ~~~
//Detecting keybord input and moving the player with that input
void Player::updateMovement(){
    //Keybord input
    //left
    if( sf::Keyboard::isKeyPressed (sf::Keyboard::Left) ){
        this->shape.move(-this->movementSpeed, 0.f);
    }
    else if( sf::Keyboard::isKeyPressed (sf::Keyboard::Right) ){
        this->shape.move(this->movementSpeed, 0.f);
    }
    if( sf::Keyboard::isKeyPressed (sf::Keyboard::Up) ){
        this->shape.move(0.f, -this->movementSpeed);
    }
    else if( sf::Keyboard::isKeyPressed (sf::Keyboard::Down) ){
        this->shape.move(0.f, this->movementSpeed);
    }
    
}

//~~~Render~~~
void Player::render(sf::RenderTarget* target){
    target->draw(this->shape);
}
