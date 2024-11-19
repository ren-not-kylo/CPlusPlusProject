//
//  Garden.cpp
//  FinalProject
//
//  Created by Chelsea Brown on 2024-11-18.
//

#include "Card.h" //so we can derive from Card

class Garden : public Card { //declaration that Garden extends Card
public:
    int getCardsPerCoin(int coins) const override{ //overriding the const = 0 from pure virtual
        switch (coins) {
            case 1:
                return 0; //Not sure if this should be 0 or throw an error for not enough coins?
            case 2:
                return 2;
            case 3:
                return 3;
            case 4:
                return 0; //same as above comment.. not sure if this is right
            default:
                return 0;
        }
    }
    
    string getName() const override{
        return "Blue";
    }
    
    void print(ostream& out) const override{
        out << "B";
    }
    
};
