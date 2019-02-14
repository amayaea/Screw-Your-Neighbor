//
// Created by Emilio Amaya on 3/7/18.
//

#include "../include/Deck.h"

// Default constructor: assigns the 52 cards to deck
Deck::Deck() : cardCount(0){
    int cardCounter = 0;
    std::string suits[] = {"Spades" , "Hearts" , "Clubs" , "Diamonds"};
    for (int i = 0 ; i < suits->length() ; ++i){
        for (int j = 1 ; j < 14 ; ++j){
            Card temp(j, suits[i]);
            myDeck[cardCounter] = temp;
            ++cardCounter;
        }
    }
}

// Get cardCount
int Deck::getCardCount() const{
    return cardCount;
}

// Shuffles the deck once all the cards are assigned
// Will also reset cardCount to be 0
void Deck::shuffle(){
    std::default_random_engine generator;
    std::uniform_int_distribution<int > distribution(0,SIZE - 1);
    for(int i = 0; i < SIZE; ++i) {
        int swapCard = distribution(generator);// generates number in the range 0 , SIZE - 1
        std::swap(myDeck[i] , myDeck[swapCard]);
    }
    cardCount = 0;
}

// Deals out one card from the deck of 52, references class card
Card Deck::dealCard(){
    cardCount++;
    return myDeck[cardCount - 1];
}
