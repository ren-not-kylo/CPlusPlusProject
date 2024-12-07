//
//  Chain.cpp
//  FinalProject
//
//  Created by Chelsea Brown on 2024-11-18.
//
/*
 Chain will have the following functions:
 - Chain(istream&, const CardFactory*) is a constructor which accepts an
 istream and reconstructs the chain from file when a game is resumed.
 - Chain<T>& operator+=(Card*) adds a card to the Chain. If the run-time type does not
 match the template type of the chain and exception of type IllegalType needs to be raised.
 - int sell() counts the number cards in the current chain and returns the number coins
 according to the function Card::getCardsPerCoin.
 - and the insertion operator (friend) to print Chain on an std::ostream. The hand should print
 a start column with the full name of the bean, for example with four cards:
 Red R R R R
 */
#include "Chain_Base.h"
#include "Card.h"

template <typename T>
class Chain : public Chain_Base {
private:
    vector<T*> cards; //vector to store the cards in the chain
public:
    Chain(istream& in, const CardFactory* cf){
        //accepts an input stream and reconstructs the chain based on its contents
    }
    
    Chain<T>& operator +=(Card* card){
        // check if the type of card matches T, which this chain should be holding
        // if not, throw an IllegalType error, otherwise add card to the vector
        if(typeid(*card) != typeid(T)){ //gotta dereference card
            //throw exception
        }
        else{
            //add card to the chain
            cards.push_back(static_cast<T*>(card));
        }
    }
    
    int sell(){
        int numCards = cards.size();
        int coins = cards.front()->getCardsPerCoin(numCards);
        return coins;
    }
    
    void print(ostream& out){
        T card = *(cards.front());
        for (int i=0; i<cards.size(); i++) {
            card.print(out);
        }
    }
};
