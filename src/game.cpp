//
//  game.cpp
//  testSFML
//
//  Created by Melanie Prettyman on 9/19/23.
//

#include "game.hpp"


/*=============================
         CONSTRUCTOR
 =============================*/

//~~~Initialize variables~~~
void Game::initializeVariables(){
    // Initialize a pointer for the game window
    this->window = nullptr;
    
    
    //Point Balls initiate
    spawnTimerMax = 10.f;
    spawnTimer = this->spawnTimerMax; //ensures first ball is spawned directly
    maxSpawnBalls = 10;
    
    //points or score
    this->pointsPlayer1 = 0;
    this->pointsPlayer2 = 0;


}

//~~~Initialize window~~~
void Game::initializeWindow(){
    // Create a new SFML RenderWindow with a specified size, title, and window style
    this->window = new sf::RenderWindow(sf::VideoMode(1280, 900), "Game", sf::Style::Titlebar | sf::Style::Close);
    
    this->window->setFramerateLimit(60);
}


//Constructor
//Open game in main with game constructor
Game::Game(){
    // Initialize game-specific variables and settings
    this->initializeVariables();
    
    // Create and initialize the game window
    this->initializeWindow();
    
    // Create and initialize the player
    this->initializePlayer();
    
    //Create and initialize font
    this->initializeFont();
    this->initializeText();

    
    
}

//~~~Destrutor~~~
Game::~Game(){
    // Cleanup: Delete the game window object when the game ends
    delete this->window;
    
    // Delete created players
    delete this->player1;
    delete this->player2;
}



/*=============================
         FUNCTIONS
 =============================*/

//    PlAyEr
//****************************

//~~~Initialize player~~~
void Game::initializePlayer(){
    
    this->player1 = new Player(1080.f, 520.f, sf::Color::Blue);
    this->player2 = new Player(280.f, 520.f, sf::Color::Red);

}


//~~~update player~~~
void Game::updatePlayer(){
    
    this->player1->update();
    this->player2->updateP2();

    
}

//~~~Render player~~~

void Game::renderPlayer(){
    this->player1->render(this->window);
    this->player2->render(this->window);

}

//    PoInT BaLlS
//****************************

//SPAWN BALLS
void Game::spawnBalls(){
    //Timer
    if(this->spawnTimer < this->spawnTimerMax){
        this->spawnTimer += 1.f;
    }
    else {//spawn
        //if the size of our vector of balls is less than the max
        if( this->swagBalls.size() < this->maxSpawnBalls ){
            
            //create a ball and put it into our vector 
            this->swagBalls.push_back( SwagBall(*this->window) );
            //reset to spawn another ball
            this->spawnTimer = 0.f;
        }
    }
    
}

//BALL -> PLAYER COLLISION
//check for collison between players and balls, then remove balls from vector of balls
void Game::updateCollision(Player& player , unsigned int& score){
    //check the collision
        //iterate through the entire vector of balls
    for( size_t i =0; i < this->swagBalls.size(); i++){
        //check each ball for a collision with the player
        //get shape, bounds of shape, and checking for intersection with another obj
        if(player.getShape().getGlobalBounds().intersects(this->swagBalls[i].getShape().getGlobalBounds())){
            
            //delete ball
            this->swagBalls.erase(this->swagBalls.begin() + i);
            //Add to points total when ball is deleted
            score++;
            player.movementSpeed += .5;
        }
    }
}

//PLAYER -> PLAYER COLLISION
//check for collison between players and balls, then remove balls from vector of balls
void Game::PVPCollision(Player& player1 , Player& player2, unsigned int& scoreP1, unsigned int& scoreP2){
    //check the collision of players
    if(player1.getShape().getGlobalBounds().intersects(player2.getShape().getGlobalBounds())){
            
            //respawn and reset score
            if (scoreP1 > scoreP2 && scoreP2 > 0){
                player2.kill();
                scoreP2--;
                player2.movementSpeed = 5.f;
                scoreP1++;
    
            }
            
            if (scoreP2 > scoreP1 && scoreP1 > 0){
                player1.kill();
                scoreP1--;
                player1.movementSpeed = 5.f;
                scoreP2++;
            }
        }
    }



//      PrInTiNg TeXt
//****************************

//~~~Initialize font~~~~
void Game::initializeFont(){
    if ( !this->font.loadFromFile ("November.ttf") ) {
        std::cout << "ERROR::GAME::INITFONTS::COULD NOT LOAD FILE\n";
    }
}

//~~~Initialize text~~~~
void Game::initializeText(){
    //gui text init
    this->guiText.setFont(this->font);
    //color the font
    this->guiText.setFillColor(sf::Color::White);
    //font size
    this->guiText.setCharacterSize(50);
    
    this->guiText.setPosition(520, 20);
    //text
    //this->guiText.setString("test");
}

//~~~render text~~~~
void Game::renderText(sf::RenderTarget* target){
    target->draw(this->guiText);
    
}

//~~~update text~~~~
void Game::updateText(){
    //s-stream that allows us to shove in all types of data and it will turn it into a string
    std::stringstream ss;
    
    ss <<"P1 Score: " << this->pointsPlayer1 << "\n";
    ss <<"P2 Score: " << this->pointsPlayer2;

    
    this->guiText.setString(ss.str());
    
    
}

//        WalLs
//****************************

void Game::setUpTiles(){
    //Boarder
    mazeVec.push_back(new GameTile(0, 0, 13.f, 768.f));
    mazeVec.push_back(new GameTile(0, 0, 284.f, 13.f));
    mazeVec.push_back(new GameTile(426, 0, 853.f, 13.f));
    mazeVec.push_back(new GameTile(1266,0, 13.f, 800.f));
    mazeVec.push_back(new GameTile(0,765, 995.f, 13.f));
    mazeVec.push_back(new GameTile(1137,765, 142.f, 13.f));
    
    //inner level 1
    mazeVec.push_back(new GameTile(142, 80, 142.f, 13.f));
    mazeVec.push_back(new GameTile(426, 82, 715.f, 13.f));
    mazeVec.push_back(new GameTile(1136, 80, 13.f, 700.f));
    mazeVec.push_back(new GameTile(142,680, 1007.f, 13.f));
    mazeVec.push_back(new GameTile(142, 80, 13.f, 250.f));
    mazeVec.push_back(new GameTile(142,515, 13.f, 177.f));
    
    //inner level 2
    mazeVec.push_back(new GameTile(260, 160, 720.f, 13.f));
    mazeVec.push_back(new GameTile(980, 160, 13.f, 420.f));
    mazeVec.push_back(new GameTile(280, 580, 713.f, 13.f));
    mazeVec.push_back(new GameTile(280, 500, 13.f, 80.f));
    mazeVec.push_back(new GameTile(287, 240, 13.f, 175.f));

    //inner level 3
    mazeVec.push_back(new GameTile(420, 240, 140.f, 15.f));
    mazeVec.push_back(new GameTile(700, 240, 140.f, 15.f));
    mazeVec.push_back(new GameTile(840, 240, 15.f, 240.f));
    mazeVec.push_back(new GameTile(420, 480, 435.f, 15.f));
    mazeVec.push_back(new GameTile(420, 400, 15.f, 80.f));
    mazeVec.push_back(new GameTile(420, 400, 80.f, 15.f));
    mazeVec.push_back(new GameTile(420, 240, 15.f, 80.f));
    
    //inner level 4
    mazeVec.push_back(new GameTile(500, 320, 260.f, 15.f));
    mazeVec.push_back(new GameTile(760, 320, 15.f, 80.f));
    mazeVec.push_back(new GameTile(680, 400, 95.f, 15.f));

    //Branches
    mazeVec.push_back(new GameTile(280, 0, 15.f, 160.f));
    mazeVec.push_back(new GameTile(420, 0, 15.f, 95.f));
    mazeVec.push_back(new GameTile(140, 415, 160.f, 15.f));
    mazeVec.push_back(new GameTile(560, 160, 15.f, 95.f));

    



}


//WALL -> PLAYER COLLISION
void Game::updateWallCollision(Player& player) {

    //check the collision
        //iterate through the entire vector of walls
    for (size_t i = 0; i < this->mazeVec.size(); i++) {
        sf::RectangleShape& wallShape = this->mazeVec[i]->getShape();
        
        //check each player for a collision with the wall
            //get shape, bounds of shape, and checking for intersection with another
        if (player.getShape().getGlobalBounds().intersects(wallShape.getGlobalBounds())) {
            // Calculate the intersection between the player and the wall
            sf::FloatRect intersection;
            if(player.getShape().getGlobalBounds().intersects(wallShape.getGlobalBounds(), intersection)) {
                // Adjust the player's position to prevent collision
                if (intersection.width < intersection.height) {
                    // Adjust horizontally
                    if (player.getShape().getPosition().x < wallShape.getPosition().x) {
                        player.getShape().move(-(intersection.width + 1), 0); // Move left of the wall
                    } else {
                        player.getShape().move(intersection.width + 1, 0); // Move right of the wall
                    }
                } else {
                    // Adjust vertically
                    if (player.getShape().getPosition().y < wallShape.getPosition().y) {
                        player.getShape().move(0, -(intersection.height + 1)); // Move above the wall
                    } else {
                        player.getShape().move(0, intersection.height + 1); // Move below the wall
                    }
                }
            }
        }
    }
}


//        GaMe
//****************************

//~~~Running~~~~
// Check if the game is running (window is open)
const bool Game::running()const{
    return this->window->isOpen();
}

//timer
sf::Clock clock1;

sf::Time elapsed1 = clock1.getElapsedTime();

//~~~UPDATE function~~~
// This function handles events (e.g., closing the window) and updates game logic
//anything that is not being drawn will go here
void Game::update(){
    
    //checking if window is open
    while (window->pollEvent(event))
    {
        // Close the game window when the close button is clicked
        if (event.type == sf::Event::Closed)
            window->close();
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window->close();
    }
    
    //Calling updatePlayer
    this->updatePlayer();
    
    //Calling the tiles for maze
    this->setUpTiles();
    
    //Calling point balls
    this->spawnBalls();
    
    //checking for collison
    this->PVPCollision(*player1, *player2, pointsPlayer1, pointsPlayer2);
    this->updateCollision(*player1, pointsPlayer1);
    this->updateCollision(*player2, pointsPlayer2);
    

    
    //print text
    this->updateText();
    
    this->updateWallCollision(*player1);
    
    
}



//~~~RENDER function~~~
//visualization, putting pixels on the screen
// This function handles rendering game objects and updating the display

void Game::render(){
    
    // Clear the previous frame with a red background
    window->clear();
    
    //DRAW YOUR GAME OBJECTS
            //player
        this->renderPlayer();
    
            //point balls
    for (auto i : this->swagBalls){
        i.render(*this->window);
    }
    
        //render maze
    for(auto i : this->mazeVec){
        i->render(this->window);
    }
    
    
            //render gui/text
    this->renderText(this->window);
    
    // Tells app to update the window's display with the new frame
    window->display();
    
}



