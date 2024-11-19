//
//  Green.cpp
//  FinalProject
//
//  Created by Chelsea Brown on 2024-11-18.
//

#include "Card.h" //so we can derive from Card

class Green : public Card { //declaration that Blue extends Card
public:
    int getCardsPerCoin(int coins) const override{ //overriding the const = 0 from pure virtual
        switch (coins) {
            case 1:
                return 3;
            case 2:
                return 5;
            case 3:
                return 6;
            case 4:
                return 7;
            default:
                return 0;
        }
    }
    
    string getName() const override{
        return "Green";
    }
    
    void print(ostream& out) const override{
        out << "G";
    }
    
};
