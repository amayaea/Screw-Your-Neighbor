//
// Created by Emilio Amaya on 3/7/18.
//

#include "../include/Card.h"

// Default Constructor
Card::Card() : value(0), suit(""){
    // nothing to do
}

// Constructor that takes a value and suit
Card::Card(uint32_t &cardValue, std::string &cardSuit) : value(cardValue), suit(cardSuit){
    // nothing to do
}

// The copy constructor.
Card::Card(const Card &rhs) : value(rhs.value), suit(rhs.suit){
    // nothing to do
}

//Destructor; Deletes the card
//Card::~Card(){
//    delete *this;
//}

// Equals Operator
const Card &Card::operator=(const Card &rhs){
    if (this != &rhs) {
        Card tmp(rhs);
        std::swap(value, tmp.value);
        std::swap(suit, tmp.suit);
    }
    return *this;
}

// Get Value
uint32_t Card::getValue() const{
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

