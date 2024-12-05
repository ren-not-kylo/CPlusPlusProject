//
//  CardFactory.h
//  FinalProject
//
//  Created by Chelsea Brown on 2024-11-24.
//

/*
 CardFactory class will have the following functions:
 - constructor in which all the cards need to be created in the numbers needed for the game (see the
 above table).
 - static CardFactory* getFactory() returns a pointer to the only instance of
 CardFactory.
 - Deck getDeck() returns a deck with all 104 bean cards. Note that the 104 bean cards are
 always the same but their order in the deck needs to be different every time. Use
 std::shuffle to achieve this.
 Also, ensure that no copies can be made of CardFactory and that there is at most one CardFactory
 object in your program.
 */

#include <stdio.h>
#include "Card.h"
#include "Deck.h"
using namespace std;
class CardFactory{
    //singleton pattern
    //define this after tradeArea
private:
    //constructor probably?
    CardFactory();
    vector<Card*> allCards; //to be used to hold each of the 104 cards
    static CardFactory* instance;
    
public:
    static CardFactory* getFactory();
    Deck getDeck();
    Card* getCard(const string& cardType);
    
    CardFactory(CardFactory&) = delete; //no copy constructor
    void operator=(const CardFactory&) = delete; //no assignment operator
    ~CardFactory() = default; // destructor
    
};
