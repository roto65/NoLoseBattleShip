#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <string>

#include "Ship.h"
#include "Pos.h"

class BattleShip : public Ship {

    public:
        BattleShip();
        BattleShip(std::string front, std::string back);

        bool action(std::string input, Player p1, Player p2) override;
        void resetShield() override;

};

#endif // BATTLESHIP_H