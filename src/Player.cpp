//
// Created by Emilio Amaya on 3/10/18.
//

#include "../include/Player.h"

// Constructor with all parameters minus myCard passed in.
Player::Player(std::string &name , int &lives, bool &user)
        : myName(name) , numLives(lives) , isCPU(user) {
}

// Get name
std::string Player::getName() const{
    return myName;
}

// Get Lives
int Player::getLives() const{
    return numLives;
}

// Get user
bool Player::getCPU() const{
    return isCPU;
}

//Get card
Card Player::getCard() const{
    return myCard;
}

void Player::setCard(Card set){
    myCard = set;
}

// Trade method
void Player::trade(Player neighbor){
    if (neighbor.myCard . getValue() == 13){
        std::cout <<  myName + "'s neighbor has a King! No trade." <<std::endl;
    }
    else{
        std::swap(myCard, neighbor.myCard);
        std::cout << myName + "traded with their neighbor." <<std::endl;
    }
}

// Trade with deck method
void Player::tradeWithDeck(Deck &cards){
    myCard = cards.dealCard();
}

// Lose Life
void Player::loseLife(){
    numLives--;
}