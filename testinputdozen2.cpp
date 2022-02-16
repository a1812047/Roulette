#include <iostream>
#include <string>

using namespace std;

int main(){
    int binOfplayingNums[12] = {0};
    int state_of_game;
    cout<<"ENTER num: ";
    cin>>state_of_game;
    enum state_of_game{
        onEto12 = 1,
        thirteeNto24,
        twentyfivEto36
    };
    int start_Num = 1;
    
    if (state_of_game == thirteeNto24){
        start_Num = 13;
        
    }else if(state_of_game == twentyfivEto36){
        start_Num = 25;
        
    }
    
    for (int i = 0; i<12; i++){
        
        binOfplayingNums[i] = start_Num++;
        cout<<binOfplayingNums[i]<<" ";
    }
    return 0;
}