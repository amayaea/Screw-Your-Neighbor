//
// Created by Emilio Amaya on 5/28/18.
//

#include "../include/Game.h"

// Creates the game
Game::Game(Player &p, int numCPU, int numLives){
    players.push_back(p);
    bool cpu = true;
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
    dealCards();

    // For Testing:
    showCards();

    makeTrades();

    showCards();

    findLosers();

    changeDealer();

    showLives();

}

void Game::dealCards(){
    // Shuffles the deck
    gameDeck.shuffle();

    // Deals cards to all the players
    for(int i = 0 ; i < players.size() ; i++){
        players[i].setCard(gameDeck.dealCard());
    }

    std::cout << "Cards have been dealt to all players\n" << std::endl;
}

void Game::showCards(){
    for (int i = 0 ; i < players.size() ; i++){
        std::cout << players[i].getName() + ": " + players[i].getCard().toString() << std::endl;
    }
}

void Game::makeTrades(){
    bool last = false;
    // Players Play
    for(int i = 0 ; i < players.size() ; i++){
        if(i == players.size() - 1)
            last = true;
        if (players[i].getCPU()){ // Is a CPU
            bool skip = CPUTrade(players[i], players[i+1], last);
            if(skip)
                i++;
        }
        else{ // Is human
            playerTrade(players[i], players[i+1], last);
        }
    }

    std::cout << "Trading has ended" << std::endl;
}

void Game::findLosers(){
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

    loseLives(losers);
}

void Game::loseLives(std::vector<Player> &losers){
    for(int m = 0 ; m < losers.size() ; m++){
        losers[m].loseLife(losers[m]);
        std::cout << losers[m].getName() + " lost!" << std::endl;
        if (losers[m].getLives() == 0)
            eliminatePlayer(losers[m]);
    }
}

void Game::changeDealer(){
    // Dealer is passed to the left
    players.push_back(players[0]);
    players.erase(players.begin());
}

void Game::showLives(){ //FIXME Lives are being decreased but always shown as initial life count
    for(int i = 0 ; i < players.size() ; i++)
        std::cout << players[i].getName() << " has " << players[i].getLives() << " lives."
                                                                              << std::endl;
}

bool Game::CPUTrade(Player &cpu, Player &neighbor, bool last){
    bool neighborLow = false;
    auto numPlayers = (int)players.size();
    int tradeThreshhold = 13 / numPlayers + 1; // Added +1 to make the games slightly more exciting
    if (cpu.getCard().getValue() <= tradeThreshhold) {
        if(last)
            cpu.tradeWithDeck(gameDeck);
        else {
            cpu.trade(neighbor);
            // If the neighbor has a lower card than the cpu,
            // they shouldn't trade their card even if it is below the threshold
            if (neighbor.getCard().getValue() > cpu.getCard().getValue() && neighbor.getCPU()) {
                neighborLow = true;
                std::cout << neighbor.getName() + " passes" << std::endl;
            }
        }
    }
    else{
        std::cout << cpu.getName() + " passes" << std::endl;
    }
    return neighborLow;

}

void Game::playerTrade(Player &p, Player &neighbor, bool last){
    std::cout << "\n";
    std::string move;
    std::cout << p.getName() << ", it's your turn! " << std::endl;
    std::cout << "Your card is " << p.getCard().toString() << std::endl;
    std::cout << "Would you like to trade or pass? (T|P)";

    int count = 0;

    while(move != "t" && move != "T" && move != "p" && move != "P") {
        getline (std::cin, move);
        if(count > 0) {
            std::cout << "Please make a valid choice " << std::endl;
            std::cout << "Would you like to trade or pass? (T|P)";
            count++;
        }
    }

    if(move[0] == 't' || move[0] == 'T'){
        if(last)
            p.tradeWithDeck(gameDeck);
        else
            p.trade(neighbor);
    }
    else if(move[0] == 'p' || move[0] == 'P')
        std::cout << p.getName() + " passes" << std::endl;
}


// Eliminates a player after they have lost all their lives
void Game::eliminatePlayer(Player loser){
    for(int i = 0 ; i < players.size() ; i++){
        if (players[i].getName() == loser.getName()) {
            players.erase(players.begin() + i);
            std::cout << loser.getName() + " has been eliminated!" << std::endl;
            if(!loser.getCPU()){
                std::cout << "Sorry, game over. Continuing play to determine winner\n" << std::endl;
            }
        }
    }
}
