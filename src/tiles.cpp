//
//  tiles.cpp
//  testSFML
//
//  Created by Melanie Prettyman on 9/20/23.
//

#include "tiles.hpp"

//Construtor
GameTile::GameTile(float x,float y, float w, float l){
    this->initiateShape(w,l);
    this->wall.setPosition(x,y);
}

//Destructor
GameTile::~GameTile(){}



//~~~initiate Shape~~~
void GameTile::initiateShape(float w, float l){
    this->wall.setFillColor(sf::Color::Red);
    this->wall.setSize(sf::Vector2f(w,l));
}

//~~~Render~~~

//~~~Render~~~
void GameTile::render(sf::RenderTarget* target){
    target->draw(this->wall);
}



//Access shape outside of private
const sf::RectangleShape& GameTile::getShape() const{
    return this->wall;
}

