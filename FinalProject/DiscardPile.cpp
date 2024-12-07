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
		char curr;
		while(in >> curr) {
			if (curr == 'b') {
				dp.push_back(fact->allCards[currIndex[0]]);
				currIndex[0]++;
			}
			if (curr == 'B') {
				dp.push_back(fact->allCards[currIndex[1]]);
				currIndex[1]++;
			}
			if (curr == 'C') {
				dp.push_back(fact->allCards[currIndex[2]]);
				currIndex[2]++;
			}
			if (curr == 'g') {
				dp.push_back(fact->allCards[currIndex[3]]);
				currIndex[3]++;
			}
			if (curr == 'G') {
				dp.push_back(fact->allCards[currIndex[4]]);
				currIndex[4]++;
			}
			if (curr == 'R') {
				dp.push_back(fact->allCards[currIndex[5]]);
				currIndex[5]++;
			}
			if (curr == 's') {
				dp.push_back(fact->allCards[currIndex[6]]);
				currIndex[6]++;
			}
			if (curr == 'S') {
				dp.push_back(fact->allCards[currIndex[7]]);
				currIndex[7]++;
			}
		}
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