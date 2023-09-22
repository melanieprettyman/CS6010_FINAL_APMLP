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
    this->endGame = false;
    
    // Initialize a pointer for the game window
    //this->window = nullptr;
    
    
    //Point Balls initiate
    spawnTimerMax = 10.f;
    spawnTimer = this->spawnTimerMax; //ensures first ball is spawned directly
    maxSpawnBalls = 6;
    
    //points or score
    this->pointsPlayer1 = 0;
    this->pointsPlayer2 = 0;


}

//~~~Initialize window~~~
void Game::initializeWindow(){
    // Create a new SFML RenderWindow with a specified size, title, and window style
    this->window = new sf::RenderWindow(sf::VideoMode(1280, 780), "Game", sf::Style::Titlebar | sf::Style::Close);
    
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
    this->window = nullptr;
    
    // Delete created players
    delete this->player1;
    this->player1 = nullptr;
    delete this->player2;
    this->player2 = nullptr;
}

//~~~End Game~~~
const bool& Game::getEndGame() const{
    return this->endGame;
}


/*=============================
         FUNCTIONS
 =============================*/

//    PlAyEr
//****************************

//~~~Initialize player~~~
void Game::initializePlayer(){
    
    this->player1 = new Player(1080.f, 520.f, 1);
    
    this->player2 = new Player(280.f, 520.f, 2);

}



bool Game::player1Wins(unsigned int& scoreP1){
    return scoreP1 >= 5;
}
bool Game::player2Wins(unsigned int& scoreP2){
    return scoreP2 >= 5;
}

//~~~update player~~~
void Game::updatePlayer(){
    
    this->player1->update();
    this->player2->updateP2();
    
    if(player1Wins(pointsPlayer1) || player2Wins(pointsPlayer2)){
        this->endGame =true;
    }
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
void Game::updateCollision(sf::Sprite& playerSprite, unsigned int& score) {
    // Check for collision
         //iterate through the entire vector of balls

    for (size_t i = 0; i < this->swagBalls.size(); i++) {
        //check each ball for a collision with the player
        //get shape, bounds of shape, and checking for intersection with another obj
        if(playerSprite.getGlobalBounds().intersects(this->swagBalls[i].getShape().getGlobalBounds())) {
            // Delete ball
            this->swagBalls.erase(this->swagBalls.begin() + i);
            // Add to points total when the ball is deleted
            score++;
    

        }
    }
}


void Game::PVPCollision(sf::Sprite& player1Sprite, sf::Sprite& player2Sprite, unsigned int& scoreP1, unsigned int& scoreP2) {
    static bool collisionHandled = false; // Static flag to track collision handling

    // Check the collision of players
    if (player1Sprite.getGlobalBounds().intersects(player2Sprite.getGlobalBounds())) {
        if (!collisionHandled) {
            // Collision is happening, handle it
            collisionHandled = true;

            // Respawn and reset score for player 2
            if (scoreP1 > scoreP2 && scoreP2 > 0) {
                // Respawn player 2 by setting its position
                player2Sprite.setPosition(600.f, 380.f);

                scoreP2 = scoreP2 - 1;
                scoreP1 += 2; // Increase player 1's score by 2
            }

            // Respawn and reset score for player 1
            if (scoreP2 > scoreP1 && scoreP1 > 0) {
                // Respawn player 1 by setting its position
                player1Sprite.setPosition(600.f, 380.f);

                scoreP1 = scoreP1 - 1;
                scoreP2 = scoreP2 + 2; // Increase player 2's score by 2
            }
        }
    } else {
        // No collision, reset the flag
        collisionHandled = false;
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
    this->guiText.setFillColor(sf::Color::Black);
    //font size
    this->guiText.setCharacterSize(50);
    
    this->guiText.setPosition(520, 20);
    
    //end game text
    this->endGameText.setFont(this->font);
    this->endGameText.setFillColor(sf::Color::Blue);
    this->endGameText.setCharacterSize(100);
    this->endGameText.setPosition(300, 300);
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
    
// Check for player wins and update endGameText accordingly
    if (player1Wins(pointsPlayer1)) {
        this->endGameText.setString("PLAYER 1 WINS! ");
    } else if (player2Wins(pointsPlayer2)) {
        this->endGameText.setString("PLAYER 2 WINS! ");
    }
    
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
    mazeVec.push_back(new GameTile(1136, 82, 13.f, 600.f));
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
void Game::updateWallCollision(sf::Sprite& player1Sprite, sf::Sprite& player2Sprite, unsigned int& scoreP1, unsigned int& scoreP2) {
    // Check the collision
    // Iterate through the entire vector of walls
    for (size_t i = 0; i < this->mazeVec.size(); i++) {
        sf::RectangleShape& wallShape = this->mazeVec[i]->getShape();

        // Check each player for a collision with the wall
        // Get bounds of the shape and check for intersection with another
        if (player1Sprite.getGlobalBounds().intersects(wallShape.getGlobalBounds())) {
            // Calculate the intersection between player1 and the wall
            sf::FloatRect intersection;
            if (player1Sprite.getGlobalBounds().intersects(wallShape.getGlobalBounds(), intersection)) {
                if (scoreP1 > 0) {
                    scoreP1--;
                }
                // Adjust the player's position to prevent collision
                if (intersection.width < intersection.height) {
                    // Adjust horizontally
                    if (player1Sprite.getPosition().x < wallShape.getPosition().x) {
                        player1Sprite.move(-(intersection.width + 1), 0); // Move left of the wall
                    } else {
                        player1Sprite.move(intersection.width + 1, 0); // Move right of the wall
                    }
                } else {
                    // Adjust vertically
                    if (player1Sprite.getPosition().y < wallShape.getPosition().y) {
                        player1Sprite.move(0, -(intersection.height + 1)); // Move above the wall
                    } else {
                        player1Sprite.move(0, intersection.height + 1); // Move below the wall
                    }
                }
            }
        }

        // Repeat the same collision detection and adjustment logic for player2
        if (player2Sprite.getGlobalBounds().intersects(wallShape.getGlobalBounds())) {
            // Calculate the intersection between player2 and the wall
            sf::FloatRect intersection;
            if (player2Sprite.getGlobalBounds().intersects(wallShape.getGlobalBounds(), intersection)) {
                if (scoreP2 > 0) {
                    scoreP2--;
                }
                // Adjust the player's position to prevent collision
                if (intersection.width < intersection.height) {
                    // Adjust horizontally
                    if (player2Sprite.getPosition().x < wallShape.getPosition().x) {
                        player2Sprite.move(-(intersection.width + 1), 0); // Move left of the wall
                    } else {
                        player2Sprite.move(intersection.width + 1, 0); // Move right of the wall
                    }
                } else {
                    // Adjust vertically
                    if (player2Sprite.getPosition().y < wallShape.getPosition().y) {
                        player2Sprite.move(0, -(intersection.height + 1)); // Move above the wall
                    } else {
                        player2Sprite.move(0, intersection.height + 1); // Move below the wall
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
    
    //if this is true, game will stop, otherwise all of these functions will
    //be updated
    if(this->endGame == false){
        //Calling updatePlayer
        this->updatePlayer();
        
        //Calling the tiles for maze
        this->setUpTiles();
        
        //Calling point balls
        this->spawnBalls();
        
        this->PVPCollision(player1->getShape(), player2->getShapeP2(), pointsPlayer1, pointsPlayer2);

        // Assuming you want to call this for player1
        this->updateCollision(player1->getShape(), pointsPlayer1);
        // Assuming you want to call this for player2
        this->updateCollision(player2->getShapeP2(), pointsPlayer2);

        
        
        //print text
        this->updateText();
        
        this->updateWallCollision(player1->getShape(), player2->getShapeP2(), pointsPlayer1, pointsPlayer2);

        
    }
}



//~~~RENDER function~~~
//visualization, putting pixels on the screen
// This function handles rendering game objects and updating the display

void Game::render(){
    sf::Color backgroundColor(255, 182, 193,255); // RGB values for light pink

    // Clear the previous frame with a red background
    window->clear(backgroundColor);
    
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
    
    //render endGame text
    if(this->endGame == true){
        this->window->draw(this->endGameText);
    }
    
    
    // Tells app to update the window's display with the new frame
    window->display();
    
}



