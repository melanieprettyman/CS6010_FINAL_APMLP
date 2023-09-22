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
    
    sprite.setScale(1, 1);
    
    this->sprite.setPosition(
        //x pos (0-size of window)
        static_cast<float>(rand() % window.getSize().x - this->sprite.getGlobalBounds().width),
        //y pos
        static_cast<float>(rand() % window.getSize().y - this->sprite.getGlobalBounds().height)
        );
    
    if (!texture.loadFromFile("points.png"))
    {
        std::cout << "Failed to load player texture!" << std::endl;
        
    }
        sprite.setTexture(texture);
    
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
    target.draw(sprite);
    
}

//Access shape which is private variable in other function s
const sf::Sprite& SwagBall::getShape() const{
    return this->sprite;
}

