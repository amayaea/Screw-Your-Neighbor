//
// Created by Emilio Amaya on 3/7/18.
//

#include "include/Game.h"

Game configure(){
    std::string playerName;
    int numLives;
    int numPlayers;

    std::cout << "What's your name? ";
    getline (std::cin, playerName);

    std::cout << "How many players would you like to play against? ";
    std::cin >> numPlayers;

    std::cout << "How many lives for each player? ";
    std::cin >> numLives;
    std::cout <<"\n";

    bool cpu = false;
    Player p(playerName, numLives, cpu);

    Game g(p, numPlayers, numLives);
    return g;
}

int main(){
    Game g = configure();
    while(g.getPlayers().size() > 1)
        g.playRound();

}