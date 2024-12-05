//
//  TradeArea.cpp
//  FinalProject
//
//  Created by Chelsea Brown on 2024-11-24.
//

#include "TradeArea.h"
#include "Card.h"

///TODO: confirm that i dont need to just use an array instead of a list here...
TradeArea::TradeArea(istream&, const CardFactory*){
    //read from input stream, send to cardfactory, add to the trade_area list?
} //constructor that reconstructs the trade area from the file, using the cardfactory

// += operator implemented in header file
    
bool TradeArea::legal(Card* c){
    bool name_exists = false;
    for(Card* card : storage_list){
        if(card->getName() == c->getName()){
            name_exists = true;
        }
        
    }
    return name_exists;
} // returns true if a card of the same bean is already in the tradearea
    
Card* TradeArea::trade(string name){ //removes a card of the corresponding bean name from the trade area, returns it
    // Creating iterator to point to first
    // element in the list
    list<Card*>::iterator itr = storage_list.begin();
    Card* result;
    
    //find the card
    for(Card* card : storage_list){
        itr++;
        if(card->getName() == name){
            result = card;
            storage_list.erase(itr);
        }
    }
    
    return result;
    
}
    
    
int TradeArea::numCards(){
    return storage_list.size();
} //returns size of tradearea list


