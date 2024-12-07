#include <iostream>
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"

using namespace std;

class Table {
private:
    Player p1, p2;
    Deck deck;
    DiscardPile dp;
    TradeArea trade;

public:
    Table(istream&, const CardFactory*);
    bool win(string&);
    void printHand(bool);
    friend ostream& operator<<(ostream& out, const Table& table) {
        return out;
    }
};