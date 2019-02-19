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
    Game(int numPlayers, int numCPU, int numLives);

    Deck getGameDeck();

    std::vector<Player> getPlayers();

    // Plays the round
    void playRound();

    void findLosers(std::vector<Player> players);

    // Eliminates a player after they have lost all their lives
    void eliminatePlayer(Player loser);

    // CPU decided to trade or not
    void CPUTrade(Player &cpu, Player &neighbor, bool last);

private:

    // The vector of players
    std::vector<Player> players;

    // The games deck
    Deck gameDeck;

};

#endif //SCREW_YOUR_NEIGHBOR_GAME_H
