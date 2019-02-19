//
// Created by Emilio Amaya on 5/28/18.
//

#include "../include/Game.h"

// Creates the game
Game::Game(int numPlayers, int numCPU, int numLives){
    bool cpu = false;
    for(int i = 0 ; i < numPlayers ; ++i){
        std::string name = "Player " + std::to_string(i+1);
        Player p(name , numLives , cpu);
        players.push_back(p);
    }
    cpu = true;
    for(int j = 0 ; j < numCPU ; ++j){
        std::string name = "CPU " + std::to_string(j+1);
        Player q(name , numLives , cpu);
        players.push_back(q);
    }

}

Deck Game::getGameDeck(){
    return gameDeck;
}

std::vector<Player> Game::getPlayers(){
    return players;
}

// Plays the round
void Game::playRound(){
    // Shuffles the deck
    gameDeck.shuffle();

    // Deals cards to all the players
    for(int i = 0 ; i < players.size() ; i++){
        players[i].setCard(gameDeck.dealCard());
    }

    std::cout << "Cards have been dealt to all players" << std::endl;

    // For Testing:
    for (int i = 0 ; i < players.size() ; i++){
        std::cout << players[i].getName() + ": " + players[i].getCard().toString() << std::endl;
    }

    bool last = false;
    // Players Play
    for(int j = 0 ; j < players.size() ; j++){
        if(j == players.size() - 1)
            last = true;
        if (players[j].getCPU()){ // Is a CPU
            CPUTrade(players[j], players[j+1], last);
        }
        else{ // Is human
            // Implement later
        }
    }

    std::cout << "Trading has ended" << std::endl;

    // For Testing:
    for (int i = 0 ; i < players.size() ; i++){
        std::cout << players[i].getName() + ": " + players[i].getCard().toString() << std::endl;
    }

    findLosers(players);

    // Dealer is passed to the left
    players.push_back(players[0]);
    players.erase(players.begin());

}

void Game::findLosers(std::vector<Player> players){
    // Loser is Decided
    std::vector<Player> losers;
    int lowCard = 14;

    // Low card is found
    for(int k = 0 ; k < players.size() ; k++){
        if(players[k].getCard().getValue() <= lowCard)
            lowCard = players[k].getCard().getValue();
    }

    // Players with the low card are added to losers vector
    for(int l = 0 ; l < players.size() ; l++){
        if(players[l].getCard().getValue() == lowCard)
            losers.push_back(players[l]);
    }

    // Each player in loser vector loses a life
    for(int m = 0 ; m < losers.size() ; m++){
        losers[m].loseLife();
        std::cout << losers[m].getName() + " lost!" << std::endl;
        if (losers[m].getLives() == 0)
            eliminatePlayer(losers[m]);
    }
}

void Game::CPUTrade(Player &cpu, Player &neighbor, bool last){
    auto numPlayers = (int)players.size();
    int tradeThreshhold = 13 / numPlayers;
    if (cpu.getCard().getValue() <= tradeThreshhold) {
        if(last)
            cpu.tradeWithDeck(gameDeck);
        else
            cpu.trade(neighbor);
    }
    else{
        std::cout << cpu.getName() + " passes" << std::endl;
    }

}

// Eliminates a player after they have lost all their lives
void Game::eliminatePlayer(Player loser){
    for(int i = 0 ; i < players.size() ; i++){
        if (players[i].getName() == loser.getName()) {
            players.erase(players.begin() + i);
            std::cout << loser.getName() + " has been eliminated!" << std::endl;
        }
    }
}
