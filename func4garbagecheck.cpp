#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int garbagecheck(int num_t_check, int firstNum, int lastNum){
    string garbage_check;
    while ((num_t_check<firstNum)&&(num_t_check>lastNum)){
        
        cout<<"Enter a integer from "<<firstNum<< " to "<< lastNum<<":";
        cin>>garbage_check;
        stringstream(garbage_check)>>num_t_check;
        if((num_t_check<firstNum)||(num_t_check>lastNum)){
        cout<<"Wrong Input!!"<<endl;
        }
    }
    
    return num_t_check;
    
}

int main(){
    cout<<"Enter a number:";
    string a;
    int b;
    cin>>a;
    stringstream(a)>> b;
    garbagecheck(b,2,5);
    
    return 0;
    
}