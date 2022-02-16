#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include "ODD_EVEN.h"
extern bool findNum(int*,int, int);
extern int stringtoNum(string );
int number_of_oddsOreven = floor(size_of_board/2);
using namespace std;

ODD_EVEN::ODD_EVEN(){
    binOfplayingNums = new int[number_of_oddsOreven];
    total_bet = 0;
    
}

void ODD_EVEN::playgame(Player* A){
    int remaining_chips = A->get_chips();
    int player_chosen_number;
    cout<<"-----------------------Choose odd or even-------------------"<<endl;
    while ( ( player_chosen_number != 1 ) && ( player_chosen_number != 2)){
        cout << " For 'ODD'  press 1 " <<endl;
        cout << "          OR         " <<endl;
        cout << " For 'EVEN' press 2" <<endl;
        string input;
        cin >>input;
        stringstream(input)>>player_chosen_number;
        if ( (player_chosen_number != 1) && (player_chosen_number != 2) ){
            cout<<"WRONG Input!!!!"<<endl;
        }
    }
    if (player_chosen_number == 1){
        state_of_game = "ODD";
    }
    else{
        state_of_game = "EVEN";
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
}

void ODD_EVEN::setBin(){
    int num = 0;
    if (state_of_game == "ODD"){
        while(num < 18){
            binOfplayingNums[num] = Game_board[(2*num)+1];
            num++;
        }
    }
    else if (state_of_game == "EVEN"){
        while(num<number_of_oddsOreven){
            binOfplayingNums[num] = Game_board[(2*num)+2];
            num++;
        }
        
    }
}

int ODD_EVEN::payout(int wheel_Outcome){
    winnings = 0;
    if(findNum(binOfplayingNums,wheel_Outcome,number_of_oddsOreven) == true){
        winnings = 3;
    }
    return winnings*total_bet;
}

void ODD_EVEN::print_Outcome(int wheel_Outcome){
    if(winnings > 0){
        cout<<"You won "<<winnings*total_bet<<"chips"<<'\n'<<endl;
        cout<<"Because you chose an "<<state_of_game<<" number like the wheel ----> "<<wheel_Outcome<<endl;
        cout<<"2 "<<"*"<<total_bet << " + "<<total_bet<<" = "<< winnings*total_bet<<endl;
        cout<<"LUCKY YOU!!!!!!!"<<'\n'<<'\n'<<endl;
        
    }else{
        cout<<"YOU LOST!!"<<total_bet<<" chips"<<'\n'<<endl;
        cout<<"Because you chose an "<<state_of_game<<" number unlike the wheel ----> "<<wheel_Outcome<<endl;
        cout<<"Your loss = "<<total_bet<<" = "<<"0 winnings"<<endl; 
    }
    
    
}

ODD_EVEN::~ODD_EVEN(){
    delete[] binOfplayingNums;
}

