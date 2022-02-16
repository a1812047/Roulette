#include <iostream>
#include "Roulette.h"
#include "Player.h"

using namespace std;

#ifndef RED_BLACK_H
#define RED_BLACK_H

class red_black:public Roulette{
    private:
        string state_of_game;
    public:
        red_black();
        
        void playgame(Player*A);
        void setBin();
        int payout(int wheel_Outcome);
        void print_Outcome(int wheel_Outcome);
        
        ~red_black();
        
};

#endif