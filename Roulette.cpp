#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

#include "Roulette.h"


extern void display_the_board();





Roulette::Roulette(){
    for(int i = 0; i<size_of_board; i++){
        Game_board[i] = i;
    }
    binOfplayingNums = Game_board;
   
}

void Roulette::display_the_table(){
    display_the_board();
}//if we change the size of the board ; edit the display_the_board function


Roulette::~Roulette(){

}


