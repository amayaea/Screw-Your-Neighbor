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

    // Default Constructor
    Card();

    // Constructor that takes a value and suit
    Card(uint32_t &cardValue, std::string &cardSuit);

    //Copy Constructor
    Card(const Card &rhs);

    // Equals Operator
    const Card &operator=(const Card &rhs);

    // Get Value
    uint32_t getValue() const;

    // Get Suit
    std::string getSuit() const;

    // Print the card
    std::string toString() const;

private:
    // value field
    uint32_t value;

    // suit field
    std::string suit;
};


#endif //SCREW_YOUR_NEIGHBOR_CARD_H
