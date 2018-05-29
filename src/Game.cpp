//
// Created by Emilio Amaya on 5/28/18.
//

#include "../include/Game.h"

// Creates the game
Game::Game(uint32_t numPlayers, u_int32_t numCPU, u_int32_t numLives){
    bool player = true;
    for(u_int32_t i = 0 ; i < numPlayers ; ++i){
        Player p = new Player("Player " + std::to_string(i+1) , numLives , true);
    }
}

// Plays the round
void Game::playRound(){

}

// Prepares the next round
void Game::prepareRound(){

}

// Eliminates a player after they have lost all their lives
std::string Game::eliminatePlayer(){

}
