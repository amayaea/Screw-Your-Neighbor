//
// Created by Emilio Amaya on 3/7/18.
//

#ifndef SCREW_YOUR_NEIGHBOR_DECK_H
#define SCREW_YOUR_NEIGHBOR_DECK_H


#include <random>
#include "../include/Card.h"
const int SIZE = 52;

class Deck {

public:
    // Default constructor: assigns the 52 cards to deck
    Deck();

    //Copy Constructor
    Deck(const Deck &rhs);

    //Destructor; Deletes the card
    ~Deck();

    // Equals Operator
    const Deck &operator=(const Deck &rhs);

    // Shuffles the deck once all the cards are assigned
    void shuffle();

    // Deals out one card from the deck of 52, refrences class card
    Card dealCard();

private:

    // An array of cards of size SIZE
    Card myDeck[SIZE];

    // Keeps track of the top card
    uint32_t cardCount;

};


#endif //SCREW_YOUR_NEIGHBOR_DECK_H
