#include <sstream>
#include <iostream>
#include <string>
#include "Single.h"
#include <algorithm>
#include <vector>

extern bool findNum(int*array,int num_to_find, int size);
extern int stringtoNum(string Any);
extern int * sort(int * array, int length);
using namespace std;

SINGLE::SINGLE(){
    cout<<"***********************************************Betting on singles***********************************************"<<endl;
    cout<<'\n'<<'\n'<<endl;
    cout<<"There are 37 spots on the board ";
    number_of_spots_to_play = 0;
}

void SINGLE::playgame(Player* A){
    int wrong_input = -1;
    int begining_num_of_chips = A->get_chips();
    int remaining_chips = begining_num_of_chips;
    
    
    
    while((number_of_spots_to_play<1) || (number_of_spots_to_play>37)){
        cout<<"How many numbers would you like to bet on (from 0 to 36 ): ";
        string garbage_check;
        cin>>garbage_check;
        stringstream(garbage_check)>>number_of_spots_to_play;
        if((number_of_spots_to_play<1) || (number_of_spots_to_play>37)){
            cout<<"Wrong Input!!"<<endl;
            cout<<"There are 37 numbers from 0 to 36";
            cout<<'\n'<<"This time enter a integer from 1 to 37"<<endl;
        }
    }
    
    chosenNums = new int[number_of_spots_to_play];
    cout<<"************************************************Choose single numbers***********************************************"<<endl;
    for (int i = 0; i<number_of_spots_to_play;i++){
        
        
        chosenNums[i] = wrong_input;
        while((chosenNums[i]<0) || (chosenNums[i]>36)){
            cout<<"Enter choice number "<<i+1<<" and press return:";
            string garbage_check;
            cin>>garbage_check;
            stringstream(garbage_check)>>chosenNums[i];
            if(((garbage_check!="0")&&(chosenNums[i]==0))||(chosenNums[i]>36)){
                cout<<'\n'<<"pay attention!!"<<endl;
                chosenNums[i] = wrong_input;
                cout<<"Enter a integer ranging from 0 to 36 this time"<<endl;
            }
        }
    
    } 
    //sort the numbers 
    sort(chosenNums,number_of_spots_to_play);
    
    
    int count = 0;
    for (int i = 0; i<number_of_spots_to_play; i++){
        
        if (chosenNums[i]!=chosenNums[i+1]){
            final_chosen_numbers.push_back(chosenNums[i]);// discard the ones that appear more than once. 
            count++;
        }
        
    }
    if(chosenNums[number_of_spots_to_play-1]!=final_chosen_numbers.back()){
            count++;
            final_chosen_numbers.push_back(chosenNums[number_of_spots_to_play-1]);
        }
    number_of_spots_to_play = count;
    //getting the amount of chips that is required for each number place.
    
    
    
    
    //select the total bets for all the chosen numbers.
    for (int i = 0; i<number_of_spots_to_play; i++){
        cout<<"Hey "<<A->getName()<<" you have "<< remaining_chips<< " remaining chips"<<'\n'<<endl;
        
        
        int input = wrong_input ;
        
        while((input>10) || (input<1)){
            cout<<"Enter the amount of chips ( 'min:1', 'max: 10' ) for chosen number "<<final_chosen_numbers[i]<<" :";
            string garbage_check;
            cin>>garbage_check;
            stringstream(garbage_check)>>input;
            
            if(input>10||input<1){
                cout<<"Wrong Input"<<endl;
                cout<<"You are only allowed a max of 10 chips and minimum 1: "<<endl;
                cout<<"Enter a valid number to bet on "<<final_chosen_numbers[i]<<'\n';
                }
                
            
        }
        total_bet = total_bet+input;
        respective_bets.push_back(input);
        remaining_chips = remaining_chips-input;
        
        while(remaining_chips < 0){
            respective_bets.pop_back();
            remaining_chips += input; 
            total_bet -= input;
            cout<<"you entered a number more than you have in your account"<<endl;
            cout<<"Enter a valid number to bet on "<<final_chosen_numbers[i]<<" :"<<'\n'<<'\n';
            input = wrong_input;
            
            while((input>10) || (input<1)){
                cout<<"Enter the amount of chips ( 'min:1', 'max: 10' ) for chosen number "<<final_chosen_numbers[i]<<" :";
                string garbage_check;
                cin>>garbage_check;
                stringstream(garbage_check)>>input;
                
                if(input>10||input<1){
                    cout<<"Wrong Input"<<endl;
                    cout<<"You are only allowed a max of 10 chips and minimum 1: "<<endl;
                    cout<<"Enter a valid number to bet on "<<final_chosen_numbers[i]<<'\n';
                    }
                
            }
        total_bet += input;
        respective_bets.push_back(input);
        remaining_chips -= input;
        
        }
        int get_1_or_2 = 0;
        if((remaining_chips == 0) && (i!=number_of_spots_to_play-1)){
            respective_bets.pop_back();
            cout<<"You have run out of chips for pending selected numbers:"<<endl;
            cout<<"Do you want to delete the rest of the bets?? "<<'\n'<<"Press 1 for yes or 2 to start again: "<<endl;
            
            cin>>get_1_or_2;
            while((get_1_or_2!=1)&&(get_1_or_2!=2)){
                cout<<"Wrong Input try again(its 1 or 2): ";
                cin>>get_1_or_2;
                }
        }
        int number_of_spots_left = number_of_spots_to_play - i;
        if(get_1_or_2 == 1){//for yes = 1 deleting the rest of the chosenNums 
            respective_bets.push_back(input);
            for(int j = 1; j<number_of_spots_left; j++){
                respective_bets.push_back(0);//by setting the rest of the chosen Nums bets amount = 0 chips.
            }
            break;
        }else if(get_1_or_2 == 2){
            cout<<"Enter all the amount of chips to bet again:"<<endl;
           
            remaining_chips = begining_num_of_chips;
            
            while(i>=0){
                respective_bets.pop_back();
                i--;
            }
            while(count>0){
            final_chosen_numbers.pop_back();
            count--;
        }
            number_of_spots_to_play = 0;
            break;
        }
        
        
    }
    
    A->change_chips(remaining_chips);
    total_bet = begining_num_of_chips - A->get_chips();
    cout<<'\n'<<'\n'<<'\n'<<endl;
    cout<<"You have bet "<<total_bet<< " chips on single numbers in total"<<endl;
    cout<<"You have "<<A->get_chips()<<" remaining chips"<<endl;
    cout<<'\n'<<'\n'<<'\n'<<endl;
     
}
//now we need to set the bins
void SINGLE::setBin(){
    binOfplayingNums = new int[number_of_spots_to_play];
    for(int i = 0; i<number_of_spots_to_play;i++){
        binOfplayingNums[i] = final_chosen_numbers[i];
    }
}

int SINGLE::payout(int wheel_Outcome){
    winnings = 0;
    if(findNum(binOfplayingNums,wheel_Outcome,number_of_spots_to_play) == true){
        for(int i = 0; i <number_of_spots_to_play; i++){
            if(binOfplayingNums[i] == wheel_Outcome){
                position = i;
            }
        }
        
        winnings = 37*respective_bets[position];
    }
    return winnings;    
}


void SINGLE::print_Outcome(int wheel_Outcome){
    if(winnings>0){
        cout<<"You WON"<<winnings<<" chips"<<'\n'<<endl;
        cout<<"Because you chose the number"<<wheel_Outcome<<" like the wheel"<<endl;
        cout<<respective_bets[position] <<" times 36 + your original bet "<<respective_bets[position] <<" = "<<winnings<<endl;
        cout<<"Lucky you!! "<<'\n'<<'\n'<<endl;
    }else{
        cout<<"You lost "<<total_bet<<" chips"<<'\n'<<endl;
        cout<<"Because you did not chose the number "<<wheel_Outcome<<" like the wheel"<<endl;
        cout<<"Better Luck next time..!! "<<'\n'<<'\n'<<endl;
    }
}


SINGLE::~SINGLE(){
    delete[] binOfplayingNums;
    delete[] chosenNums;
}