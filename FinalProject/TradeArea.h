//
//  TradeArea.h
//  FinalProject
//
//  Created by Chelsea Brown on 2024-11-24.
//

/*
 The TradeArea holds cards in a std::list, and will have the following functions:
 - TradeArea(istream&, const CardFactory*) is a constructor which accepts an
 istream and reconstruct the TradeArea from file.
 - TradeArea& operator+=(Card*) adds the card to the trade area but it does not check if it
 is legal to place the card.
 - bool legal(Card*) returns true if the card can be legally added to the TradeArea, i.e., a
 card of the same bean is already in the TradeArea.
 - Card* trade(string) removes a card of the corresponding bean name from the trade area.
 - int numCards() returns the number of cards currently in the trade area.
 - and the insertion operator (friend) to insert all the cards of the trade area to an std::ostream.
 */
#include <iostream>
#include <list>
#include "Card.h"
#include "CardFactory.h"

using namespace std;
class TradeArea {
private:
    list<Card*> storage_list;
    
public:
    TradeArea(istream&, const CardFactory*); //constructor that reconstructs the trade area from the file, using the cardfactory
    TradeArea& operator+=(Card* c){
        storage_list.push_back(c); //add it to the back of the storage list?
    } //adds the card to the trade area (after checking legality)
    
    bool legal(Card*); // returns true if a card of the same bean is already in the tradearea
    
    Card* trade(string); //removes a card of the corresponding bean name from the trade area
    
    int numCards(); //returns size of tradearea list
    
    friend ostream& operator<<(ostream& out, const TradeArea& trade_area){
        for (Card* card : trade_area.storage_list) { //print each card to the output stream
            card->print(out);
        }
        return out; //then return the stream
    }
};
