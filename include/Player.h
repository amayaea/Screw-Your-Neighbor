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
    Player(std::string &name , uint32_t &lives, bool &user);

    // Copy Constructor
    Player(const Player &rhs);

    // Destructor?

    // Get name
    std::string getName() const;

    // Get Lives
    uint32_t getLives() const;

    // Get user
    bool getCPU() const;

    // Get card
    Card getCard() const;

    // Set card
    void setCard(Card set);

    // Trade method
    void trade(Player neighbor);

    // Trade with deck method
    void tradeWithDeck(Deck cards);

    // Lose Life
    void loseLife();

private:

    // Player name
    std::string myName;

    // Player's Lives
    uint32_t numLives;

    // Bool if CPU or user. 
    bool isCPU;

    // Player's card for round
    Card myCard;
};

#endif //SCREW_YOUR_NEIGHBOR_PLAYER_H
