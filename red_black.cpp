#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

#include "red_black.h"

extern bool findNum(int*,int, int);
extern int stringtoNum(string );
extern void disp_RB();

int number_of_redsorblacks = floor(size_of_board/2);

using namespace std;

red_black::red_black(){
    binOfplayingNums = new int[number_of_redsorblacks];
    total_bet = 0;
}

void red_black::playgame(Player*A){
    
    int remaining_chips = A->get_chips();
    
    int player_chosen_number= 0;
    cout<<"-----------------------Choose red or black-------------------"<<endl;
    disp_RB();
    while ( ( player_chosen_number != 1 ) && ( player_chosen_number != 2)){
        cout << " For 'RED'  press 1 " <<endl;
        cout << "          OR         " <<endl;
        cout << " For 'BLACK' press 2" <<endl;
        string input;
        cin >>input;
        stringstream(input)>>player_chosen_number;
        if ( (player_chosen_number != 1) && (player_chosen_number != 2) ){
            cout<<"WRONG Input!!!!"<<endl;
        }
    }
    if (player_chosen_number == 1){
        state_of_game = "RED";
    }
    else{
        state_of_game = "BLACK";
    }
    cout<<endl;
    cout<<endl;
    cout<<"You have chosen, "<<state_of_game<<endl;
    cout<<"and "<<A->getName()<<", you have "<<A->get_chips()<<" remaining chips"<<endl;
    cout<<"Please select the amount of chips you want to bet for this game: "<<endl;
    string garbageG;
    cin>>garbageG;
    stringstream(garbageG)>>total_bet;
    
    //garbage_check;
    while((total_bet>remaining_chips)||(total_bet<=0)){
        cout<<A->getName()<<", you only have "<<A->get_chips()<<" remaining chips"<<endl;
        cout<<"Please select the amount of chips you have to bet for this game: "<<endl;
        string garbage_check;
        cin>>garbage_check;
        stringstream(garbage_check)>>total_bet;
        
    }
    remaining_chips = remaining_chips - total_bet;
    
    A->change_chips(remaining_chips);
    cout<<'\n'<<'\n';
    cout<<"You have "<<remaining_chips<<" remaining chips"<<endl;
    cout<< "You bet "<<total_bet<<" on "<<state_of_game<<endl;
    cout<<endl;
}

void red_black::setBin(){
    int num = 0;
    if(state_of_game == "RED"){
        
        for(num = 0;num<18; num++){
            int binNumber = Game_board[(2*num)+1];
            if((binNumber<10)||((binNumber>=19) && (binNumber<=28))) {
                    binOfplayingNums[num] = binNumber;

            }else{
                binOfplayingNums[num] = binNumber+1;
            }
        }
    }else if(state_of_game == "BLACK"){
        for(num = 0;num<18; num++){
            int binNumber = Game_board[(2*num)+1];
            if((binNumber<10)||((binNumber>=19) && (binNumber<=28))) {
                    binOfplayingNums[num] = binNumber+1;

            }else{
                binOfplayingNums[num] = binNumber;
            }
        }
    }
}



int red_black::payout(int wheel_Outcome){
    winnings = 0;
    if(findNum(binOfplayingNums,wheel_Outcome,number_of_redsorblacks) == true){
        winnings = 3;
    }
    return winnings*total_bet;
}


void red_black::print_Outcome(int wheel_Outcome){
    
    if(winnings > 0){
        disp_RB();
        cout<<"You won "<<winnings*total_bet<<"chips"<<'\n'<<endl;
        cout<<"Because you chose "<<state_of_game<<" number like the wheel ----> "<<wheel_Outcome<<endl;
        cout<<"2 "<<"*"<<total_bet << " + "<<total_bet<<" = "<< winnings*total_bet<<endl;
        cout<<"LUCKY YOU!!!!!!!"<<'\n'<<'\n'<<endl;
        
    }else{
        disp_RB();
        cout<<"YOU LOST!!"<<total_bet<<" chips"<<'\n'<<endl;
        cout<<"Because you chose "<<state_of_game<<" number unlike the wheel ----> "<<wheel_Outcome<<endl;
        cout<<"Your loss = "<<total_bet<<" = "<<"0 winnings"<<endl; 
    }
    
    
}


red_black::~red_black(){
    delete[] binOfplayingNums;
}