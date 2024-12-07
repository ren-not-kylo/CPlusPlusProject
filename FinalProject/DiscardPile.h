#include <vector>
#include <iostream>
#include "Card.h"
#include "CardFactory.h"

using namespace std;

class DiscardPile {
private:
    vector<Card*> dp;
    

public:
    DiscardPile(istream&, const CardFactory*);  
    DiscardPile& operator+=(Card*);
    Card* pickUp();
    Card* top();
    void print(ostream&);
    friend ostream& operator<<(ostream& out, const DiscardPile& discPile) {
        return out;
    }

}