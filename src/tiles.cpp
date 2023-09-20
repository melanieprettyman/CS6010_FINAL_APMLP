//
//  tiles.cpp
//  testSFML
//
//  Created by Melanie Prettyman on 9/20/23.
//

#include "tiles.hpp"

//Construtor
GameTile::GameTile(float x,float y){
    this->initiateShape();
    this->wall.setPosition(x,y);
}

//Destructor
GameTile::~GameTile(){}



//~~~initiate Shape~~~
void GameTile::initiateShape(){
    this->wall.setFillColor(sf::Color::Red);
    this->wall.setSize(sf::Vector2f(50.f,300.f));
}

//~~~Render~~~

//~~~Render~~~
void GameTile::render(sf::RenderTarget* target){
    target->draw(this->wall);
}





