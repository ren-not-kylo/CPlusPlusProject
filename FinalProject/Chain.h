//
//  Chain.h
//  FinalProject
//
//  Created by Chelsea Brown on 2024-11-18.
//
#include <iostream>
#include "Card.h"
#include "Chain_Base.h"


using namespace std;

template<class T>
class Chain {
private:
    Chain(istream&, const CardFactory*);
    
    vector<T> cards;

public:
    Chain<T>& operator+=(Card*);
    
    int sell();

    friend ostream& operator<<(ostream& out, const Chain& chain) {
        return out;
    }
};
