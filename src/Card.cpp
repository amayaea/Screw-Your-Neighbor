//
// Created by Emilio Amaya on 3/7/18.
//

#include "../include/Card.h"

// Default Constructor
Card::Card() = default;

// Constructor that takes a value and suit
Card::Card(int &cardValue, std::string &cardSuit) : value(cardValue), suit(cardSuit){
    // nothing to do
}

// Get Value
int Card::getValue() const{
    return value;
}

// Get Suit
std::string Card::getSuit() const{
    return suit;
}

// Print the card
std::string Card::toString() const{
    std::string result;
    if (value == 1){
        result += "Ace ";
    }
    if (value > 1 && value < 11){
        result += std::to_string(value);
    }
    if (value == 11){
        result += "Jack ";
    }
    if (value == 12){
        result += "Queen ";
    }
    if (value == 13){
        result += "King ";
    }
    result += "of " + suit;
    return result;
}

