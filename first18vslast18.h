#include <iostream>
#include "Roulette.h"
#include "Player.h"

using namespace std;

#ifndef FIRST18VSLAST18_H
#define FIRST18VSLAST18_H

class first18vslast18:public Roulette{
private:
    string state_of_game;
public:
    first18vslast18();
    void playgame(Player*A);
    void setBin();
    int payout(int wheel_Outcome);
    void print_Outcome(int wheel_Outcome);
    ~first18vslast18();
};



#endif