//
//  Tests.cpp
//  testSFML
//
//  Created by Aiden Pratt on 9/20/23.
//

#include "Tests.hpp"
#include "game.hpp"
#include "player.hpp"



void testGame(){


    Game game; // Create a Game object

    // Test that the window pointer is not nullptr
    assert(game.getWindow() != nullptr);

    // Test that the initial points for both players are 0
    assert(game.getPointsPlayer1() == 0);
    assert(game.getPointsPlayer2() == 0);

    // Test that the player objects are not nullptr
    assert(game.getPlayer1() != nullptr);
    assert(game.getPlayer2() != nullptr);

    // Test that the maze vector has been initialized with some tiles
    assert(game.getMazeVec().size() > 0);

    // Test that the spawn timer values are initialized correctly
    assert(game.getSpawnTimerMax() == 10.0f);
    assert(game.getSpawnTimer() == 10.0f);
    assert(game.getMaxSpawnBalls() == 10);


}


void testPlayer(){

    // Test case for Player constructor and initialization
    Player player(100.f, 200.f, sf::Color::Red);

    // Check that the initial position matches the provided values
    assert(player.getShape().getPosition().x == 100.f);
    assert(player.getShape().getPosition().y == 200.f);

    // Check that the player shape is initialized with the provided color
    assert(player.getShape().getFillColor() == sf::Color::Red);


    // Test case for Player movement functions

    // Move the player and check its new position
    player.updateMovement();
    assert(player.getShape().getPosition().x == 95.f); // Move left
    assert(player.getShape().getPosition().y == 200.f);

    player.updateMovement();
    assert(player.getShape().getPosition().x == 90.f); // Move left again
    assert(player.getShape().getPosition().y == 200.f);

    player.updateMovementPlayer2();
    assert(player.getShape().getPosition().x == 85.f); // Move left with Player 2
    assert(player.getShape().getPosition().y == 200.f);

    // Test case for Player window boundaries

    // Move the player beyond the window boundaries
    player.updateMovement();
    assert(player.getShape().getPosition().x == 1280.f); // Wrap to the right
    assert(player.getShape().getPosition().y == 0.f);

    player.updateMovementPlayer2();
    assert(player.getShape().getPosition().x == 1275.f); // Move left with Player 2
    assert(player.getShape().getPosition().y == 0.f);


}


