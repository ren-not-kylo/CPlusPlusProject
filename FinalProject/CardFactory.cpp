//
//  CardFactory.cpp
//  FinalProject
//
//  Created by Chelsea Brown on 2024-11-24.
//
/*
 - constructor in which all the cards need to be created in the numbers needed for the game (see the
 above table).
 - static CardFactory* getFactory() returns a pointer to the only instance of
 CardFactory.
 - Deck getDeck() returns a deck with all 104 bean cards. Note that the 104 bean cards are
 always the same but their order in the deck needs to be different every time. Use
 std::shuffle to achieve this.
 Also, ensure that no copies can be made of CardFactory and that there is at most one CardFactory
 object in your program.
 */

#include "CardFactory.h"
#include "Card.h"
#include "Blue.h"
#include "Chili.h"
#include "Stink.h"
#include "Green.h"
#include "Soy.h"
#include "Black.h"
#include "Red.h"
#include "Garden.h"
#include <vector>
#include <random>

using namespace std;

CardFactory::CardFactory(){
    //create all cards: 20 Blue, 18 Chili, 16 Stink, 14 Green, 12 Soy, 10 Black, 8 Red, 6 Garden
    for(int i=0; i< NUM_OF_BLUE; i++){
        allCards.emplace_back(new Blue()); //add a new unique blue card
    }
    for(int i=0; i< NUM_OF_CHILLI; i++){
        allCards.emplace_back(new Chili()); //add a new unique blue card
    }
    for(int i=0; i< NUM_OF_STINK; i++){
        allCards.emplace_back(new Stink()); //add a new unique blue card
    }
    for(int i=0; i< NUM_OF_GREEN; i++){
        allCards.emplace_back(new Green()); //add a new unique blue card
    }
    for(int i=0; i< NUM_OF_SOY; i++){
        allCards.emplace_back(new Soy()); //add a new unique blue card
    }
    for(int i=0; i< NUM_OF_BLACK; i++){
        allCards.emplace_back(new Black()); //add a new unique blue card
    }
    for(int i=0; i< NUM_OF_RED; i++){
        allCards.emplace_back(new Red()); //add a new unique blue card
    }
    for(int i=0; i< NUM_OF_GARDEN; i++){
        allCards.emplace_back(new Garden()); //add a new unique blue card
    }
    
}

CardFactory* CardFactory::getFactory(){
    if(instance == nullptr){
        instance = new CardFactory();
    }
    return instance;
}

Deck CardFactory::getDeck(){
    vector<Card*> deckCards;
    for (const auto& card : allCards){
        deckCards.push_back(card);
    }
    auto rng = default_random_engine {}; //random number generator
    ranges::shuffle(deckCards.begin(), deckCards.end(), rng); //randomize cards
    
    return Deck(deckCards); //TODO: make sure Jarrett knows to have a second constructor that takes a vector of cards, essentially a copy constructor
}
