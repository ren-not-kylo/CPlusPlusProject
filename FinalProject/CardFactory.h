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

// global variables to be used to populate containers from CardFactory

// number of each type of card
const int NUM_OF_BLACK = 10;
const int NUM_OF_BLUE = 20;
const int NUM_OF_CHILLI = 18;
const int NUM_OF_GARDEN = 6;
const int NUM_OF_GREEN = 14;
const int NUM_OF_RED = 8;
const int NUM_OF_SOY = 12;
const int NUM_OF_STINK = 16;
const int TOTAL_CARDS = 104;

// array which stores the index of the next card of each type in allCards (in alphabetical order)
int currIndex[TOTAL_CARDS] = { 0,                                  
                        currIndex[0] + NUM_OF_BLACK,
                        currIndex[1] + NUM_OF_BLUE,
                        currIndex[2] + NUM_OF_CHILLI,
                        currIndex[3] + NUM_OF_GARDEN,
                        currIndex[4] + NUM_OF_GREEN,
                        currIndex[5] + NUM_OF_RED,
                        currIndex[6] + NUM_OF_SOY,
                      };

// index of first instance of each card type in allCards
const int BLACK_START_IN = currIndex[0];
const int BLUE_START_IN = currIndex[1];
const int CHILI_START_IN = currIndex[2];
const int GARDEN_START_IN = currIndex[3];
const int GREEN_START_IN = currIndex[4];
const int RED_START_IN = currIndex[5];
const int SOY_START_IN = currIndex[6];
const int STINK_START_IN = currIndex[7];

class CardFactory{
    //singleton pattern
    //define this after tradeArea
private:
    //constructor probably?
    CardFactory();
    static CardFactory* instance;
    
public:
    vector<Card*> allCards; //to be used to hold each of the 104 cards  
    static CardFactory* getFactory();
    Deck getDeck();
    Card* getCard(const string& cardType);
    
    CardFactory(CardFactory&) = delete; //no copy constructor
    void operator=(const CardFactory&) = delete; //no assignment operator
    ~CardFactory() = default; // destructor
};
