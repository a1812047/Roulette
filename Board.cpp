/*this board is a function which displays the numbers as it appears on the table of roulette.
*/
#include <iostream>
#include <string>


using namespace std;

void display_the_board(){
    
    cout<<'\n'<<endl;
    for(int i = 1; i<=3;i++){
        if(i!=2){
            cout<<"  ";
            
        }else {
            cout<<" "<<0;
        }
        int previous_num = i;
        cout<<"   "<<previous_num<<"  ";
        for(int j = 1; j<12; j++){
            
            int next_num = previous_num+3;
            
            if((next_num>=10)&&(next_num<=12)||(next_num>=22)&&(next_num<=24)){
                cout<<next_num<<"   ";
            }else{
                cout<<next_num<<"  ";
            }
            
            previous_num = next_num;
        }
        cout<<'\n'<<'\n'<<endl;
    }
}
