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
Player::~Player(){}



//~~~initiate Shape~~~
void Player::initiateShape(sf::Color a){
    this->shape.setFillColor(a);
    this->shape.setSize(sf::Vector2f(50.f,50.f));
}

//~~~initiate variable~~~
void Player::initiateVariable(){
    this->movementSpeed=5.f;
//    this->hpMax = 10;
//    this->hp = hpMax;
}


//Functions

//~~~update~~~
void Player::update(){
    //Detecting keybord input and moving the player with that input
    this->updateMovement();
}

//~~~update player 2~~~
void Player::updateP2(){
    
    //Detecting keybord input and moving the player with that input
    this->updateMovementPlayer2();
}

//~~~window boundaries ~~~
void Player::windowBoundaries(){
    auto newPosition = shape.getPosition();
      newPosition.x += 0;
      newPosition.y += 0;
       
    //top
      if(newPosition.y < 0 && newPosition.x > 200 && newPosition.x < 450) {
        newPosition.y += 750;
          newPosition.x = 1040;
       
      }
    //bottom
      if(newPosition.y > 780 && newPosition.x > 900 && newPosition.x < 1200){
        newPosition.y -= 780;
        newPosition.x = 330;
       
      }
      shape.setPosition(newPosition);
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
    
    this->windowBoundaries();
    
}

//~~~update movement player 2~~~
//Detecting keybord input and moving the player with that input
void Player::updateMovementPlayer2(){
    //Keybord input
    //left
    if( sf::Keyboard::isKeyPressed (sf::Keyboard::A) ){
        this->shape.move(-this->movementSpeed, 0.f);
    }
    else if( sf::Keyboard::isKeyPressed (sf::Keyboard::D) ){
        this->shape.move(this->movementSpeed, 0.f);
    }
    if( sf::Keyboard::isKeyPressed (sf::Keyboard::W) ){
        this->shape.move(0.f, -this->movementSpeed);
    }
    else if( sf::Keyboard::isKeyPressed (sf::Keyboard::S) ){
        this->shape.move(0.f, this->movementSpeed);
    }
    this->windowBoundaries();
}

//~~~Kill~~~
void Player::kill(){
    auto killPosition = shape.getPosition();
    shape.setPosition(600, 380);
}


//~~~Render~~~
void Player::render(sf::RenderTarget* target){
    target->draw(this->shape);
}


//Access shape outside of private 
sf::RectangleShape& Player::getShape() {
    return this->shape;
}
