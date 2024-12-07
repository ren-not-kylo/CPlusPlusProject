//
//  Deck.h
//  FinalProject
//
//  Created by Chelsea Brown on 2024-11-24.
//

#include <vector>
#include <iostream>
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
