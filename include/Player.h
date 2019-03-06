//
// Created by Emilio Amaya on 3/10/18.
//

#ifndef SCREW_YOUR_NEIGHBOR_PLAYER_H
#define SCREW_YOUR_NEIGHBOR_PLAYER_H

#include "Deck.h"
#include "Card.h"
#include <string>

class Player{
public:

    // Constructor with all parameters minus myCard passed in.
    Player(std::string &name , int &lives, bool &user);

    // Get name
    std::string getName() const;

    // Get Lives
    int getLives() const;

    // Get user
    bool getCPU() const;

    // Get card
    Card getCard() const;

    // Set card
    void setCard(Card set);

    // Trade method
    void trade(Player &neighbor);

    // Trade with deck method
    void tradeWithDeck(Deck &cards);

    // Lose Life
    void loseLife(Player &player);

private:

    // Player name
    std::string myName;

    // Player's Lives
    int numLives;

    // Bool if CPU or user. 
    bool isCPU;

    // Player's card for round
    Card myCard;
};

#endif //SCREW_YOUR_NEIGHBOR_PLAYER_H
