#include <iostream>
#include <vector>
#include "Roulette.h"
#include "Player.h"
using namespace std;
#ifndef SINGLES_H
#define SINGLES_H

class SINGLE:public Roulette{
  private:
    int number_of_spots_to_play;
    int * chosenNums;
    vector <int> final_chosen_numbers;
    vector <int> respective_bets;
    int position;
  public:
    SINGLE();
    void playgame(Player* toplay);
    void setBin();
    int payout(int wheel_Outcome);
    void print_Outcome(int wheel_Outcome);
    ~SINGLE();
};
#endif