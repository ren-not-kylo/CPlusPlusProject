#include <string>
#include <list>
#include <iostream>
#include "Hand.h"
#include "Card.h"
#include "Chain.h"

using namespace std;

class Player {
private:
    int coins;
    int MaxNumChains;
    int numChains;
    string name;
    Hand hand;
    vector<Chain<Card> > chains;

public:
    Player(string&);
    Player(iostream&, const CardFactory*);
    string getName();
    int getNumCoins();
    Player& operator+=(int);
    int getMaxNumChains();
    Chain<Card>& operator[](int);
    void buyThirdChain();
    void printHand(bool);
    friend ostream& operator<<(ostream& out, const Player p) {
        return out;
    }
};