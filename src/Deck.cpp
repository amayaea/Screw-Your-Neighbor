//
// Created by Emilio Amaya on 3/7/18.
//

#include "../include/Deck.h"

// Default constructor: assigns the 52 cards to deck
Deck::Deck(){
    std::vector<std::string> suits = {"Spades" , "Hearts" , "Clubs" , "Diamonds"};
    for (int i = 0 ; i < suits.size() ; ++i){
        for (int j = 1 ; j < 14 ; ++j){
            Card temp;
            temp.setValue(j);
            temp.setSuit(suits[i]);
            myDeck.push_back(temp);
        }
    }
}

std::vector<Card> Deck::getDeck() {
    return myDeck;
}

// Shuffles the deck once all the cards are assigned
void Deck::shuffle(){
    std::random_shuffle(myDeck.begin(), myDeck.end());
}

// Deals out one card from the deck of 52, references class card
Card Deck::dealCard(){
    myDeck.push_back(myDeck.front());
    myDeck.erase(myDeck.begin());
    return myDeck.back();
}
