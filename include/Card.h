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

public:

    Card();

    // Get Value
    int getValue() const;

    // Get Suit
    std::string getSuit() const;

    void setValue(int &val);

    void setSuit(std::string &s);

    // Print the card
    std::string toString();

private:
    // value field
    int value;

    // suit field
    std::string suit;
};


#endif //SCREW_YOUR_NEIGHBOR_CARD_H
