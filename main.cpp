//
// Created by Emilio Amaya on 3/7/18.
//

#include "include/Game.h"

int main(){
    // Testing::

    /*Card test;
    std::string heart = "Hearts";
    test.setSuit(heart);
    int one = 1;
    test.setValue(one);
    std::cout << test.toString() << std::endl;*/

    /*Deck testDeck;
    testDeck.shuffle();
    for (int i = 0 ; i < SIZE ; i++){
        std::cout << testDeck.getDeck()[i].toString() << std::endl;
    }
    std::cout << std::endl;*/

    Game g(0, 10, 1);
    while(g.getPlayers().size() > 1) {
        g.playRound();
    }

}