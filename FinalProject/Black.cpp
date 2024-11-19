//
//  Black.cpp
//  FinalProject
//
//  Created by Chelsea Brown on 2024-11-18.
//

#include "Card.h" //so we can derive from Card

class Black : public Card { //declaration that Black extends Card
public:
    int getCardsPerCoin(int coins) const override{ //overriding the const = 0 from pure virtual
        switch (coins) {
            case 1:
                return 2;
            case 2:
                return 4;
            case 3:
                return 5;
            case 4:
                return 6;
            default:
                return 0;
        }
    }
    
    string getName() const override{
        return "Black";
    }
    
    void print(ostream& out) const override{
        out << "b";
    }
    
};
