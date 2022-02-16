#include <string>
#include <iostream>

using namespace std;

void disp_RB(){
    
    int num = 0;
    int red_numbers[18];
    int blackies[18];
    
    
        
    for(num = 0;num<18; num++){
        int binNumber = (2*num)+1;
        if((binNumber<10)||((binNumber>=19) && (binNumber<=28))) {
                red_numbers[num] = binNumber;
        }else{
            red_numbers[num] = binNumber+1;
        }
    }
    num = 0;
    for(num = 0; num<18; num++){
        int binNumber = (2*num)+1;
       if((binNumber<10)||((binNumber>=19) && (binNumber<=28))) {
                blackies[num] = binNumber+1;
        }else{
            blackies[num] = binNumber;
        }
    }
 
    cout<<"Reds :   ";
    for(int i = 0; i<18; i++){
        cout<<" "<<red_numbers[i]<<" ";
    }
    cout<<endl;
    cout<<"Blackies:";
    for(int j = 0; j<18; j++){
        cout<<" "<<blackies[j]<<" ";
    }
    cout<<endl;
    
}

