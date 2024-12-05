//
//  Hand.h
//  FinalProject
//
//  Created by Chelsea Brown on 2024-11-29.
//
/*
 - Hand(istream&, const CardFactory*) is a constructor which accepts an istream
    and reconstruct the Hand from file.
 - Hand& operator+=(Card*) adds the card to the rear of the hand.
 - Card* play() returns and removes the top card from the player's hand.
 - Card* top() returns but does not remove the top card from the player's hand.
 - Card* operator[](int) returns and removes the Card at a given index.
 - and the insertion operator (friend) to print Hand on an std::ostream. The hand should print
    all the cards in order.
 */

#include <iostream>
#include "CardFactory.h"
#include "Card.h"
class Hand{ //implemented by a queue
private:
    
public:
    Hand(istream&, const CardFactory*); //constructor to reconstruct the Hand from file
    Hand& operator+=(Card*); //adds the Card to the rear of the hand
    Card* play(); //returns and removes top card
    Card* top(); //returns but doesn't remove the top card
    Card* operator[](int); //returns and removes the Card at a given index
    
    friend ostream& operator<<(ostream& out, const Hand& hand){
        for (Card* card : hand.cards) { //print each card to the output stream
            card->print(out);
        }
        return out; //then return the stream
    }
}
