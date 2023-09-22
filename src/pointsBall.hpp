//
//  pointsBall.hpp
//  testSFML
//
//  Created by Melanie Prettyman on 9/19/23.
//

#ifndef pointsBall_hpp
#define pointsBall_hpp

#include <stdio.h>
#include "player.hpp"


class SwagBall
{
private:
    
    sf::CircleShape shape;
    void initiateShape(const sf::RenderWindow& window);
    
    sf::Sprite sprite;
    sf::Texture texture ;
    
public:
    SwagBall(const sf::RenderWindow& window);
    ~SwagBall();
    
    //Methods
    void update();
    void render(sf::RenderTarget& target);
    const sf::Sprite& getShape() const;
    
};


#endif /* pointsBall_hpp */
