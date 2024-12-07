#include <vector>
#include <iostream>
#include "Card.h"
#include "CardFactory.h"

using namespace std;

class DiscardPile {

	//instance variables
	vector<Card*> dp;

	// constructor for loading a saved DiscardPile
	DiscardPile(istream& in, const CardFactory* fact) {
		
	}

	// adds a card to the DiscardPile
	DiscardPile& operator+=(Card* c) {
		dp.push_back(c);
	}

	// removes and returns the top card from the pile
	Card* pickUp() {
		Card* temp = dp.back();
		dp.pop_back();
		return temp;
	}

	// returns the top card from the pile
	Card* top() {
		return dp.back();
	}

	
	void print(std::ostream& out) {
		for (int i = 0; i < dp.size(); i++) {
			dp[i]->print(out);
		}
	}

	friend ostream& operator<<(ostream& out, DiscardPile discP) {
		discP.dp.back()->print(out);
		return out;
	}

};