//
//  Card.h
//  FinalProject
//
//  Created by Chelsea Brown on 2024-11-18.
//
/*
 Create the bean card and its derived classes:
 - Card is the base class and will be abstract
 - Blue, Chili, Stink, Green, soy, black, Red and garden are derived
 classes (from Card) and will have to be concrete classes.
 A bean card can be printed to console with its first character of its name.
 Card class will have the following pure virtual functions:
 - virtual int getCardsPerCoin(int coins) will implement in the derived classes
 the above table for how many cards are necessary to receive the corresponding number of coins.
 - virtual string getName() returns the full name of the card (e.g., Blue).
 - virtual void print(ostream& out) inserts the first character for the card into the
 output stream supplied as argument. If the first character is the same for two cards, use uppercase
 for the first one and lowercase for the second one (For example B for Blue and b for Black).
 - and a global stream insertion operator for printing any objects of such a class which implements
 the “Virtual Friend Function Idiom” with the class hierarchy.
 */

#include <iostream>
using namespace std;

class Card {
public:
    virtual ~Card(); //destructor
    virtual int getCardsPerCoin(int coins) const = 0; //pure virtual, and must be implemented by derived classes
    virtual string getName() const = 0;
    virtual void print(ostream& out) const = 0;
    //and a global stream insertion operator for printing any objects of such a class which implements the “Virtual Friend Function Idiom” with the class hierarchy.
    // ^^ whatever that means
    friend ostream& operator<<(ostream& out, const Card& card){ //friends of the card class can access this
        //new custom << operation that takes an output stream, and assigns a card to it
        card.print(out); //will put the card's face value onto the stream
        return out; //then return the stream
    }
};

