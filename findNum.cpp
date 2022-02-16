#include <iostream>
using namespace std;

bool findNum(int*array,int num_to_find, int size){
    for(int i = 0; i<size; i++){
        if(array[i]==num_to_find){
            return true;
            break;
        }
    }
    return false;
}
