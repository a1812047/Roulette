#include<iostream>
#include "Roulette.h"
#include "Player.h"

using namespace std;

#ifndef DOZENS_H
#define DOZENS_H

class DOZENS:public Roulette{
    private:
        int state_of_game;
        string state_of_dozen;
    public:
        DOZENS();
        void playgame(Player*A);
        void setBin();
        int payout(int wheel_Outcome);
        void print_Outcome(int wheel_Outcome);
        ~DOZENS();
};
#endif