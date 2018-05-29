//
// Created by Emilio Amaya on 3/10/18.
//

#include "../include/Player.h"

// Constructor with all parameters passed in.
Player::Player(std::string &name , uint32_t &lives, bool &user)
        : myName(name) , numLives(lives), isCPU(user){

}

// Copy Constructor
Player::Player(const Player &rhs){

}

// Destructor?

// Get name
std::string Player::getName() const{
    return myName;
}

// Get Lives
uint32_t Player::getLives() const{
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
        std::cout << "Your neighbor has a King! No trade, you've been screwed!" <<std::endl;
    }
    else{
        std::swap(myCard, neighbor.myCard);
    }
}

// Trade with deck method
void Player::tradeWithDeck(Deck cards){
    myCard = cards.dealCard();
}

// Lose Life
void Player::loseLife(){
    numLives--;
}