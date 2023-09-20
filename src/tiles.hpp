//
//  tiles.hpp
//  testSFML
//
//  Created by Melanie Prettyman on 9/20/23.
//

#ifndef tiles_hpp
#define tiles_hpp

#include <stdio.h>
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



class GameTile{
    
    
private:
    
    sf::RectangleShape wall;
    void initiateShape();
    
public:
    //Construtor
    GameTile(float x,float y);
    ~GameTile();
    
    //Methods
    void render(sf::RenderTarget* target);



    
};

#endif /* tiles_hpp */
