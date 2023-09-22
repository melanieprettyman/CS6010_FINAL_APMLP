//
//  player.cpp
//  testSFML
//
//  Created by Melanie Prettyman on 9/19/23.
//

#include "player.hpp"

//Construtor
Player::Player(float x, float y,float player){
    this->sprite.setPosition(x,y);
    this->sprite2.setPosition(x,y);
    // Set the scale for both sprites
        this->sprite.setScale(1, 1);
        this->sprite2.setScale(1, 1);

    
    if (player == 1){
        this->initiatePlayer1(player);
    }
    if(player ==2){
        this->initiatePlayer2(player);
    }
}

//Destructor
Player::~Player(){}



//~~~initiate Shape~~~
void Player::initiatePlayer1(float player){
    //this->shape.setFillColor(a);
    //this->shape.setSize(sf::Vector2f(30.f,45.f));
    
    if (!texture.loadFromFile("player1.png"))
    {
        std::cout << "Failed to load player texture!" << std::endl;
        
    }
        sprite.setTexture(texture);
        this->initiateVariable();
    }
    
    


void Player::initiatePlayer2(float player){

    if (!texture2.loadFromFile("player2.png"))
    {
        std::cout << "Failed to load player texture!" << std::endl;

    }
        sprite2.setTexture(texture2);
        this->initiateVariable();
}


//~~~initiate variable~~~
void Player::initiateVariable(){
    this->movementSpeed=5.f;
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
    auto newPosition = sprite.getPosition();
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
      sprite.setPosition(newPosition);
}

//~~~window boundaries ~~~
void Player::windowBoundaries2(){
    auto newPosition = sprite2.getPosition();
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
      sprite2.setPosition(newPosition);
}


//~~~update movement ~~~
//Detecting keybord input and moving the player with that input
void Player::updateMovement(){
    //Keybord input
    //left
    if( sf::Keyboard::isKeyPressed (sf::Keyboard::Left) ){
        this->sprite.move(-this->movementSpeed, 0.f);
    }
    else if( sf::Keyboard::isKeyPressed (sf::Keyboard::Right) ){
        this->sprite.move(this->movementSpeed, 0.f);
    }
    if( sf::Keyboard::isKeyPressed (sf::Keyboard::Up) ){
        this->sprite.move(0.f, -this->movementSpeed);
    }
    else if( sf::Keyboard::isKeyPressed (sf::Keyboard::Down) ){
        this->sprite.move(0.f, this->movementSpeed);
    }
    
    this->windowBoundaries();
    
}

//~~~update movement player 2~~~
//Detecting keybord input and moving the player with that input
void Player::updateMovementPlayer2(){
    //Keybord input
    //left
    if( sf::Keyboard::isKeyPressed (sf::Keyboard::A) ){
        this->sprite2.move(-this->movementSpeed, 0.f);
    }
    else if( sf::Keyboard::isKeyPressed (sf::Keyboard::D) ){
        this->sprite2.move(this->movementSpeed, 0.f);
    }
    if( sf::Keyboard::isKeyPressed (sf::Keyboard::W) ){
        this->sprite2.move(0.f, -this->movementSpeed);
    }
    else if( sf::Keyboard::isKeyPressed (sf::Keyboard::S) ){
        this->sprite2.move(0.f, this->movementSpeed);
    }
    this->windowBoundaries2();
}


//~~~Render~~~
void Player::render(sf::RenderTarget* target){
    target->draw(this->sprite);
    target->draw(this->sprite2);

}


//Access shape outside of private 
sf::Sprite& Player::getShape() {
    return this->sprite;
}

//Access shape outside of private
sf::Sprite& Player::getShapeP2() {
    return this->sprite2;
}
