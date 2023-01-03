#include <iostream>
#include <string>

#include "BattleShip.h"
#include "Pos.h"

BattleShip::BattleShip(){

}

BattleShip::BattleShip(std::string front, std::string back){
    Pos F (front);
    Pos B (back);    //conversione da stringa a pos
    if (distance(F, B) != 4.0) {
        throw illegal_length();
    }
    if(F.x == B.x) {
        _facing = 1;
    } else {
        _facing = 0;
    }
    _midPos.x = (F.x + B.x) / 2;
    _midPos.y = (F.y + B.y) / 2;
    _length = 5;
    _upperChar = 'C';
    _lowerChar = 'c';
    resetShield();
}

bool BattleShip::action(std::string XYTarget, Player p1, Player p2){
    Pos I (XYTarget);
    if((I.x<12&&I.x>=0)&&(I.y<12&&I.y>=0)){
        return false;
    }
    else{
        for(Ship* s : p2.getDefenceField().getShipArray()){
            std::vector<Pos> segments = getSegments(s);
            int i = 0;
            for(Pos p : segments){
                if(p==I){
                    p1.getAttackField().insertChar('X', I);
                    s->getShield()[i] = s->getLowerChar();
                    return true;
                }
                i++;
            }
        }
        p1.getAttackField().insertChar('O', I);
        return true;
    }
    
}
