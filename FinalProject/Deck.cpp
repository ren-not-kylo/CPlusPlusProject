
#include <vector>
#include <iostream>
#include "CardFactory.h"
#include "Card.h"

using namespace std;

class Deck : vector<Card*> {

    vector<Card*>  deck;

	// constructor for loading a saved Deck
	Deck(istream& in, const CardFactory* fact) {
		int count = 0;
		
	}
	
	// Desctructor
	~Deck() {}

	// returns a pointer to the Card at the top of the deck
	Card* draw() {	
		if (!deck.empty()) {						// checks if the deck is empty							
			Card* out = (deck.back());	
			deck.pop_back();
			return out;		
		} else {
			throw invalid_argument("Deck is empty. Game over!");		// if the deck is empty, throws error indicating the game is over
		}
	}	

	friend ostream& operator<<(ostream& out, const Deck& d) {
        for (int i = 0; i < d.deck.size(); i++ ) {
			d.deck[i]->print(out);
		}
		return out;
    }

};