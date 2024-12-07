//
//  Hand.cpp
//  FinalProject
//
//  Created by Chelsea Brown on 2024-11-29.
//

#include <iostream>
#include <queue>
#include <exception>
#include "CardFactory.h"
#include "Card.h"

using namespace std;

class Hand{ //implemented by a queue

    queue<Card*> cards;
    Hand(istream&, const CardFactory*) {

    }
    Hand& operator+=(Card*) {

    }

    Card* play() {
        Card* toPlay = cards.front();
        cards.pop();
        return toPlay;
    }

    Card* top() {
        return cards.front();
    }

    Card* operator[](int i) {
        int size = cards.size();
        Card* out;
        if (i < size) {
            queue<Card*> temp;
            for (int i = 0; i < size; i++) {
                temp.push(cards.front());
                cards.pop();
            }
            out = cards.front();
            cards.pop();
            while(!cards.empty()) {
                temp.push(cards.front());
                cards.pop();
            }
            cards.swap(temp);         
        } else {
            throw out_of_range("out of bounds");
        }
    }
    
    friend ostream& operator<<(ostream& out, const Hand& hand) {
        while (!hand.cards.empty()) { //print each card to the output stream
            hand.cards.front()->print(out);
        }
        return out; //then return the stream
    }
};