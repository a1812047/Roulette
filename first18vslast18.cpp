#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include "first18vslast18.h"

extern bool findNum(int*,int, int);
extern int stringtoNum(string );

const int size18 = 18;

using namespace std;

first18vslast18::first18vslast18(){
    binOfplayingNums = new int[size18];
    total_bet = 0;

}


void first18vslast18::playgame (Player*A){
    int remaining_chips = A->get_chips();
    int player_chosen_number;
    cout<<"-----------------------Choose first_18 or last_18-------------------"<<endl;

    cout<<"First 18's are numbers from 1 to 18"<<endl;
    cout<<"last 18's are numbers from 19 to 36"<<endl;


    while ( ( player_chosen_number != 1 ) && ( player_chosen_number != 2)){
        cout << " For 'first_18'  press 1 " <<endl;
        cout << "          OR         " <<endl;
        cout << " For 'last_18' press 2" <<endl;
        string input;
        cin >>input;
        stringstream(input)>>player_chosen_number;
        if ( (player_chosen_number != 1) && (player_chosen_number != 2) ){
            cout<<"WRONG Input!!!!"<<endl;
        }
    }
    if (player_chosen_number == 1){
        state_of_game = "first_18";
    }
    else{
        state_of_game = "last_18";
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


void first18vslast18::setBin(){
    int num = 1;

    if (state_of_game == "first_18"){
        while(num<=18){
            binOfplayingNums[num] = Game_board[num];
            num++;
        }
    }else if(state_of_game == "last_18"){
        while(num<=18){
            binOfplayingNums[num] = Game_board[num+18];
            num++;
        }
    }

}


int first18vslast18::payout(int wheel_Outcome){
   winnings = 0;
    if(findNum(binOfplayingNums,wheel_Outcome,size18) == true){
        winnings = 3;
    }
    return winnings*total_bet;
}

void first18vslast18::print_Outcome(int wheel_Outcome){
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

first18vslast18::~first18vslast18(){
    delete[] binOfplayingNums;
}


