#include <iostream>
#include <sstream>
#include <string>
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
    Table(istream& in , const CardFactory* fact) {
        // isntance variables
        string deckIn;
        string dpIn;
        string taIn;
        string p1In;
        string p2In;
        string component;
        istringstream ss;

        // sparating the istream into each line
        while(in >> component) {
            if (component == "DECK") getline(in, deckIn, '\n');
            if (component == "DISCPILE") getline(in, dpIn, '\n');
            if (component == "TRADEAREA") getline(in, taIn, '\n');
            if (component == "PLAYER1") getline(in, p1In, '\n');
            if (component == "PLAYER2") getline(in, p2In, '\n');
        }
        
        // constructing each component from the strings
        istringstream deckInSS(deckIn);
        Deck d(deckInSS, fact);
        
        istringstream dpInSS(dpIn);
        DiscardPile dp(dpInSS, fact);

        istringstream taInSS(taIn);
        TradeArea ta(taInSS, fact);


        istringstream p1InSS(p1In);
        Player p1(p1InSS, fact);

        istringstream p2InSS(p2In);
        Player p2(p2InSS, fact);
    }

    bool win(string& winner) {
        if (d.deck.size() == 0) {

            return true;
        } else {
            return false;
        }
    }

    void printHand(bool) {
        
    }

    friend ostream& operator<<(ostream& out, const Table& table) {
        return out;
    }
};