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

    // Default Constructor
    Player();

    // Constructor with all parameters passed in.
    Player(std::string name , uint32_t lives, bool user, Card card);

    // Copy Constructor
    Player(const Player &rhs);

    // Destructor?

    // Get name
    std::string getName() const;

    // Get Lives
    uint32_t getLives() const;

    // Get user
    bool getUser() const;

    //Get card
    bool getCard() const;

    // Trade method
    void trade(Player neighbor);

    // Trade with deck method
    void tradeWithDeck();

    // Lose Life
    void loseLife();

private:

    // Player name
    std::string myName;

    // Player's Lives
    uint32_t myLives;

    // Bool if CPU or user
    bool isUser;

    // Player's card for round
    Card myCard;
};

#endif //SCREW_YOUR_NEIGHBOR_PLAYER_H
