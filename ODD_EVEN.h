#include <iostream>
#include "Roulette.h"
#include "Player.h"
using namespace std;
#ifndef ODD_EVEN_H
#define ODD_EVEN_H

class ODD_EVEN:public Roulette{
  private:
    string state_of_game;
  public:
    ODD_EVEN();
    
  
    void playgame(Player*A);
    void setBin();
    int payout(int wheel_Outcome);
    void print_Outcome(int wheel_Outcome);
    ~ODD_EVEN();
};
#endif