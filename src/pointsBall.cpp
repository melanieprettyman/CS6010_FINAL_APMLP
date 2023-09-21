//
//  pointsBall.cpp
//  testSFML
//
//  Created by Melanie Prettyman on 9/19/23.
//

#include "pointsBall.hpp"

/*=============================
         CONSTRUCTOR
 =============================*/

//Initiate point balls to be small and white
void SwagBall::initiateShape(const sf::RenderWindow& window){
    this->shape.setRadius(15.f);
    this->shape.setFillColor(sf::Color::White);
    //randomize postion
    this->shape.setPosition(
        //x pos (0-size of window)
        static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().width),
        //y pos
        static_cast<float>(rand() % window.getSize().y - this->shape.getGlobalBounds().height)
        );
}
    
//~~~Constructor~~~
SwagBall::SwagBall(const sf::RenderWindow& window){
    this-> initiateShape(window);
}

//~~~Destructor~~~
SwagBall::~SwagBall(){
}

 
/*=============================
         METHODS
 =============================*/

//void SwagBall::update(){}


//~~~Render~~~

void SwagBall::render(sf::RenderTarget& target){
    target.draw(this->shape);
    
}

//Access shape which is private variable in other function s
const sf::CircleShape& SwagBall::getShape() const{
    return this->shape;
}

