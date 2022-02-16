#include <iostream>
#include "Player.h"
#ifndef size_of_board
#define size_of_board 37
#endif

#ifndef ROULETTE_H
#define ROULETTE_H
class Roulette{
  //it has board with 0 to 36 on it! 
  public:
  int winnings;
  int total_bet;
  int Game_board[size_of_board];
  int* binOfplayingNums;
  //int wheel_Outcome;
  Roulette();
  void display_the_table();
  //int get_Outcome();
  virtual void playgame(Player * toplay)=0;
  virtual void setBin()=0;
  virtual int payout(int)=0;
  virtual void print_Outcome(int wheel_Outcome)=0;
  virtual~Roulette();
  
};
#endif

