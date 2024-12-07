//
//  Deck.h
//  FinalProject
//
//  Created by Chelsea Brown on 2024-11-24.
//
#ifndef DECK_H
#define DECK_H
#include <vector>
#include <iostream>
#include "CardFactory.h"
#include "Card.h"

using namespace std;

class Deck{ 
    vector<Card*> deck;
    
public:
    Deck(istream&, const CardFactory*);
    
    Card* draw();
    
    friend ostream& operator<<(ostream& out, const Deck& d) {
        for (int i = 0; i < d.deck.size(); i++ ) {
			d.deck[i]->print(out);
		}
		return out;
    }
};
#endif
