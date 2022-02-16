#include <iostream>
#include <string>
#include <cstdlib>
#include<sstream>
using namespace std;

int main(){
  cout<<"********************Choose the dozen from three below********************"<<endl;
    int chosen_block_of_dozen =0;
    
    while((chosen_block_of_dozen!=1) &&(chosen_block_of_dozen!=2) &&(chosen_block_of_dozen!=3)){
        cout<<'\n'<<"1. for numbers 1 to 12"<<endl;
        cout<<"2. for numbers 13 to 24"<<endl;
        cout<<"3. for numbers 25 to 36"<<endl;
        cout<< "Enter 1|2|3: ";
        string input;
        cin>>input;
        stringstream(input)>>chosen_block_of_dozen;
        
        if((chosen_block_of_dozen<1) || (chosen_block_of_dozen>3)){
            cout<<'\n'<<'\n'<<"Dont waste our time:"<<endl;
        }
        
    } 
    

    return 0;
}