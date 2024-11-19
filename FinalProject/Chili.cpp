//
//  Chili.cpp
//  FinalProject
//
//  Created by Chelsea Brown on 2024-11-18.
//

#include "Card.h" //so we can derive from Card

class Chili : public Card { //declaration that Chili extends Card
public:
    int getCardsPerCoin(int coins) const override{ //overriding the const = 0 from pure virtual
        switch (coins) {
            case 1:
                return 3;
            case 2:
                return 6;
            case 3:
                return 8;
            case 4:
                return 9;
            default:
                return 0;
        }
    }
    
    string getName() const override{
        return "Chili";
    }
    
    void print(ostream& out) const override{
        out << "C";
    }
    
};
