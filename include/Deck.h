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

    std::vector<Card> getDeck();

    // Shuffles the deck once all the cards are assigned
    void shuffle();

    // Deals out one card from the deck of 52, refrences class card
    Card dealCard();

private:

    // An array of cards of size SIZE
    std::vector<Card> myDeck;

};


#endif //SCREW_YOUR_NEIGHBOR_DECK_H
