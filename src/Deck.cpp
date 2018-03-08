//
// Created by Emilio Amaya on 3/7/18.
//

#include "../include/Deck.h"

// Default constructor: assigns the 52 cards to deck
Deck::Deck() : cardCount(0){
    uint32_t cardCount = 0;
    std::string suits[] = {"Spades" , "Hearts" , "Clubs" , "Diamonds"};
    for (uint32_t i = 0 ; i < suits->length() ; ++i){
        for (uint32_t j = 1 ; j < 14 ; ++j){
            Card temp(j, suits[i]);
            myDeck[cardCount] = temp;
            ++cardCount;
        }
    }
}

//Copy Constructor
Deck::Deck(const Deck &rhs) : cardCount(rhs.cardCount) {
    // Do I need to do anything with myDeck?
}

//Destructor; Deletes the card
Deck::~Deck(){
    delete *this;
}

// Equals Operator
const Deck &Deck::operator=(const Deck &rhs){
    if (this != &rhs) {
        Deck tmp(rhs);
        std::swap(myDeck, tmp.myDeck);
        std::swap(cardCount, tmp.cardCount);
    }
    return *this;
}

// Shuffles the deck once all the cards are assigned
// Will also reset cardCount to be 0
void Deck::shuffle(){
    std::default_random_engine generator;
    std::uniform_int_distribution<uint32_t > distribution(0,SIZE - 1);
    for(uint32_t i = 0; i < SIZE; ++i) {
        uint32_t swapCard = distribution(generator);// generates number in the range 0 , SIZE - 1
        std::swap(myDeck[i] , myDeck[swapCard]);
    }
    cardCount = 0;
}

// Deals out one card from the deck of 52, refrences class card
Card Deck::dealCard(){
    cardCount++;
    return myDeck[cardCount - 1];
}
