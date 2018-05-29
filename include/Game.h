//
// Created by Emilio Amaya on 5/28/18.
//

#ifndef SCREW_YOUR_NEIGHBOR_GAME_H
#define SCREW_YOUR_NEIGHBOR_GAME_H

#include "Deck.h"
#include "Player.h"
#include <vector>
#include <string>


class Game{
public:
    // Creates the game
    Game(uint32_t numPlayers, u_int32_t numCPU, u_int32_t numLives);

    // Plays the round
    void playRound();

    // Prepares the next round
    void prepareRound();

    // Eliminates a player after they have lost all their lives
    std::string eliminatePlayer();

private:

    // The vector of players
    std::vector<Player> players;

    // The games deck
    Deck gameDeck;

};

#endif //SCREW_YOUR_NEIGHBOR_GAME_H
