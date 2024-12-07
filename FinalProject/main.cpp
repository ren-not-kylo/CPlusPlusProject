//
//  main.cpp
//  FinalProject
//
//  Created by Chelsea Brown on 2024-11-18.
/*
 Setup:
 • Input the names of 2 players. Initialize the Deck and draw 5 cards for the Hand of each Player; or
 • Load paused game from file.
 While there are still cards on the Deck
     if pause save game to file and exit
     For each Player
         Display Table
         Player draws top card from Deck
         If TradeArea is not empty
            Add bean cards from the TradeArea to chains or discard them.
         Play topmost card from Hand.
         If chain is ended, cards for chain are removed and player receives coin(s).
         If player decides to
            Play the now topmost card from Hand.
         If chain is ended, cards for chain are removed and player receives coin(s).
         If player decides to
         Show the player's full hand and player selects an arbitrary card
         Discard the arbitrary card from the player's hand and place it on the discard pile.
         Draw three cards from the deck and place cards in the trade area
         while top card of discard pile matches an existing card in the trade area
            draw the top-most card from the discard pile and place it in the trade area
         end
         for all cards in the trade area
         if player wants to chain the card
            chain the card.
         else
            card remains in trade area for the next player.
         end
         Draw two cards from Deck and add the cards to the player's hand (at the back).
     end
 end
 */

#include <iostream>
#include <fstream>
#include <string>
#include "Deck.h"
#include "TradeArea.h"
#include "Table.h"
#include "Hand.h"
#include "DiscardPile.h"
using namespace std;


int main(int argc, const char * argv[]) {
    CardFactory* factory = CardFactory::getFactory();
    string p1, p2;
    cout << "Can i even run this" << endl;
    //setup
    cout << "Enter Player 1's name: ";
    cin >> p1;
    cout << "Enter Player 2's name: ";
    cin >> p2;
    
    //TODO: INITIALIZE ISTREAM
    ifstream file ("test.txt");
    string str;
    //initialize deck, add 5 cards to each hand
    Deck d = factory->getDeck();
    DiscardPile dp(file, factory); //FIX THIS
    Hand h1(file, factory);
    Hand h2(file, factory);
    TradeArea tradearea(file, factory);
    Table table(file, factory);
    
    //add 5 cards to each hand
    for(int i=0; i<5; i++){
        h1+=d.draw();
        h2+=d.draw();
    }
    
    while(!d.isEmpty()){
        //check if player pauses the game
        string pause;
        cout << "Pause game? (Y/N) ";
        cin >> pause;
        if (pause[0] == 'Y'){
            //print current game state to file
            break;
        }
        //otherwise continue game
        cout << "PLAYER 1 TURN" << endl;
        //display table
        cout << "Table: " << endl; // print table?
        h1+=d.draw(); //draw another card from the deck
        // If TradeArea is not empty Add bean cards from the TradeArea to chains or discard them.
        
        /*
         Player draws top card from Deck
         
         If TradeArea is not empty
            Add bean cards from the TradeArea to chains or discard them.
         Play topmost card from Hand.
         If chain is ended, cards for chain are removed and player receives coin(s).
         If player decides to
            Play the now topmost card from Hand.
         If chain is ended, cards for chain are removed and player receives coin(s).
         If player decides to
         Show the player's full hand and player selects an arbitrary card
         Discard the arbitrary card from the player's hand and place it on the discard pile.
         Draw three cards from the deck and place cards in the trade area
         while top card of discard pile matches an existing card in the trade area
            draw the top-most card from the discard pile and place it in the trade area
         end
         for all cards in the trade area
         if player wants to chain the card
            chain the card.
         else
            card remains in trade area for the next player.
         */
    }
    //start game loop
    
}
