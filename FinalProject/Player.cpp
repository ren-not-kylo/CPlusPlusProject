#include <string>
#include <list>
#include <iostream>
#include <string>
#include "Hand.h"
#include "Card.h"
#include "Chain.h"

using namespace std;

class Player {
private:
    int coins;
    int maxNumChains;
    string name;
    Hand hand;
    vector<Chain<Card> > chains;

public:
    Player(string& name) {
        coins = 0;
        maxNumChains = 2;
        name = name;
    }

    Player(iostream&, const CardFactory*) {

    }

    string getName() const {
        return name;
    }

    int getNumCoins() const {
        return coins;
    }

    Player& operator+=(int c) {
        coins = coins + c;
    }

    int getMaxNumChains() const {
        return maxNumChains;
    }

    const Chain<Card>& operator[](int i) const {
        return chains[i];
    }

    void buyThirdChain() {
        this->maxNumChains = 3;
    }

    void printHand(bool top) {
        if(!hand.cards.empty()) {
            if(top) {
                hand.cards.front()->print(cout);
            } else {
                queue temp = hand.cards;
                while(!temp.empty()) {
                    hand.cards.front()->print(cout);
                    hand.cards.pop();
                    cout << " ";
                }
            }
        } else {
            cout << endl;
        }
    }

    friend ostream& operator<<(ostream& out, const Player p) {

        out << p.getName() << " " << p.getMaxNumChains() << " " << p.getNumCoins() << " " << p.hand << " " 
        << p[1] << " " << p[2] << " " << p[3];

    }
};