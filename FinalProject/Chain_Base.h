//
//  Chain_Base.h
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

#include <iostream>
using namespace std;
class Chain_Base {
    
public:
    virtual ~Chain_Base() = default; //default destructor
    //constructor not needed, because it'll be a copy constructor implemented in derived class
    // += operator will also be done in derived class
    virtual int sell() const = 0; //pure virtual
    virtual void print(ostream out) const = 0; //because we need to print the chain at some point
    
    friend ostream& operator<<(ostream& out, const Chain_Base& chain_base){ //friends of the chain_base class can access this
        //new custom << operation that takes an output stream, and prints a chain to it
        chain_base.print(out);
        return out; //then return the stream
    }
};
