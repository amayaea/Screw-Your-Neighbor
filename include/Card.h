//
// Created by Emilio Amaya on 3/7/18.
//

#ifndef SCREW_YOUR_NEIGHBOR_CARD_H
#define SCREW_YOUR_NEIGHBOR_CARD_H

#include <stdexcept>
#include <iostream>
#include <string>

class Card {
public:

    // Default constructor
    Card();

    // Constructor that takes a value and suit
    Card(int &cardValue, std::string &cardSuit);

    // Get Value
    int getValue() const;

    // Get Suit
    std::string getSuit() const;

    // Print the card
    std::string toString() const;

private:
    // value field
    int value;

    // suit field
    std::string suit;
};


#endif //SCREW_YOUR_NEIGHBOR_CARD_H
