
#include <vector>
#include <iostream>
#include "CardFactory.h"
#include "Card.h"

using namespace std;

class Deck : vector<Card*> {

    vector<Card*>  deck;

	// constructor for loading a saved Deck
	Deck(istream& in, const CardFactory* fact) {
		char curr;
		while(in >> curr) {
			if (curr == 'b') {
				deck.push_back(fact->allCards[currIndex[0]]);
				currIndex[0]++;
			}
			if (curr == 'B') {
				deck.push_back(fact->allCards[currIndex[1]]);
				currIndex[1]++;
			}
			if (curr == 'C') {
				deck.push_back(fact->allCards[currIndex[2]]);
				currIndex[2]++;
			}
			if (curr == 'g') {
				deck.push_back(fact->allCards[currIndex[3]]);
				currIndex[3]++;
			}
			if (curr == 'G') {
				deck.push_back(fact->allCards[currIndex[4]]);
				currIndex[4]++;
			}
			if (curr == 'R') {
				deck.push_back(fact->allCards[currIndex[5]]);
				currIndex[5]++;
			}
			if (curr == 's') {
				deck.push_back(fact->allCards[currIndex[6]]);
				currIndex[6]++;
			}
			if (curr == 'S') {
				deck.push_back(fact->allCards[currIndex[7]]);
				currIndex[7]++;
			}
		}
		
	}

	// returns a pointer to the Card at the top of the deck
	Card* draw() {							
		Card* out = (deck.back());	
		deck.pop_back();
		return out;		
	}	

	friend ostream& operator<<(ostream& out, const Deck& d) {
        for (int i = 0; i < d.deck.size(); i++ ) {
			d.deck[i]->print(out);
		}
		return out;
    }

};