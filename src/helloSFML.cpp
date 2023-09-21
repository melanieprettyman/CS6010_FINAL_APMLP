#include <SFML/Graphics.hpp>
#include "game.hpp"


//updated maze to be more accurate
//added in tests for game class and player class
//ending game/player death
//changed background color and tile color 
int main()
{
    //seed random number generator
    std::srand( static_cast<unsigned>(time (0) ) );
    
    //Initialize game engine
    Game game;
    
    // run the program as long as the window is open
    //calling method that checks if the window is open
    while (game.running())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        
        //Update
        // Update the game logic and handle events
        game.update();
        
        //Render
        // Render the game objects and display them on the window
        game.render();
        
    }
    return 0;

}
