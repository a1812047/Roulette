#include <string>
#include <iostream>
#include "DOZENS.h"
#include <sstream>

extern bool findNum(int*,int, int);

using namespace std;

int numbers_in_a_dozen = 12;//12 is a dozen.
DOZENS::DOZENS(){
    binOfplayingNums = new int[numbers_in_a_dozen];
    total_bet = 0;
}

void DOZENS::playgame(Player*A){
    
    cout<<"********************Choose the dozen from three below********************"<<endl;
    
    
    //decide the block of dozens amongst three blocks(1-12;13-24;25-36)  )
    int chosen_block_of_dozen =0;
    
    while((chosen_block_of_dozen!=1) &&(chosen_block_of_dozen!=2) &&(chosen_block_of_dozen!=3)){
        cout<<'\n'<<"1. for all numbers 1 to 12 press 1"<<endl;
        cout<<"2. for all numbers 13 to 24 press 2"<<endl;
        cout<<"3. for all numbers 25 to 36 press 3"<<endl;
        cout<< "Enter 1|2|3: ";
        string input;
        cin>>input;
        stringstream(input)>>chosen_block_of_dozen;
        
        if((chosen_block_of_dozen<1) || (chosen_block_of_dozen>3)){
            cout<<'\n'<<'\n'<<"Dont waste our time:"<<endl;
        }
    }
    
    
    
    
    
    // number decided.
    enum chosen_block_of_dozen{
        oneTo12 = 1,
        thirteenTo24,
        twentyfiveTo36
    };
    
    
    //inform the player his bet.
    cout<<'\n'<<'\n'<<"Hey "<<A->getName()<<" ";
    if(chosen_block_of_dozen == oneTo12){
        state_of_game = 1;
        state_of_dozen = "1st twelves (1-12)";
        cout<<"You chose to bet on numbers from 1 to 12"<<endl;
    }else if(chosen_block_of_dozen==thirteenTo24){
        state_of_game = 2;
        state_of_dozen = "2nd twelves (12-24)";
        cout<<"You chose to bet on numbers from 13 to 24"<<endl;
    }else if (chosen_block_of_dozen == twentyfiveTo36){
        state_of_game = 3;
        state_of_dozen = "3rd twelves (25-36)";
        cout<<"You chose to bet on numbers from 25 to 36"<<endl;
    }
    
    
    
    
    int remaining_chips = A->get_chips();
    cout<<'\n'<<"You have "<<remaining_chips<<" remaining chips"<<endl;
    cout<<"Place your bet"<<endl;
    
    
    while((total_bet<=0) || (total_bet>remaining_chips)){
        cout<<"Enter the total amount of chips for this game:";
        string input2;
        cin>>input2;
        stringstream(input2)>>total_bet;
        cout<<'\n';

        if((total_bet<=0) || (total_bet>remaining_chips)){
            cout<<'\n';
            cout<<A->getName()<<", you have "<<A->get_chips()<<" remaining chips"<<endl;
            cout<<"Please select the amount of chips you 'have'---> between 1 and "<<remaining_chips<< " to bet for this game: "<<endl;
            cout<<'\n';
        }
        
        cout<<'\n';
        
        
    }
    
    remaining_chips -= total_bet;
    //change the remaining chips for the player.
    A->change_chips(remaining_chips);
    cout<<"You have "<<remaining_chips<<" remaining chips"<<endl;
    cout<< "You bet "<<total_bet<<" chips on "<<state_of_dozen<<endl;
    
    cout<<'\n';
    cout<<'\n';

    
}

void DOZENS::setBin(){
    int start_Num ;
    if (state_of_game == 2){
        start_Num = 13;
    }else if(state_of_game == 3){
        start_Num = 25;
    }else{
        start_Num = 1;
    }
    
    
    
    for (int i = 0; i<12; i++){
        binOfplayingNums[i] = start_Num++;
    }
     
}



int DOZENS::payout(int wheel_Outcome){
    winnings = 0;
    if(findNum(binOfplayingNums,wheel_Outcome,numbers_in_a_dozen)==true){
        winnings = 3;
    }
    return winnings*total_bet;
}

void DOZENS::print_Outcome(int wheel_Outcome){
    if(winnings>0){
        cout<<"YOU WIN"<<winnings*total_bet<<'\n'<<'\n'<<endl;
        cout<<"Because you chose the right dozen of numbers : "<<state_of_dozen<<endl;
        cout<<"wheel stopped at "<<wheel_Outcome<<", a number in "<<state_of_dozen;
        cout<<'\n'<<'\n'<<endl;
    }else{
        cout<<"YOU LOST"<<winnings*total_bet<<'\n'<<'\n'<<endl;
        cout<<"Because you chose the wrong dozen of numbers : "<<state_of_dozen<<endl;
        cout<<"wheel stopped at "<<wheel_Outcome<<", a number nowhere in "<<state_of_dozen;
        cout<<'\n'<<'\n'<<endl;
    }
}

DOZENS::~DOZENS(){
    delete[] binOfplayingNums;
}