#include <iostream>

using namespace std;

int* sort(int*array,int length){
    int j = length-1;
    while(j!=0){
        for(int i =1; i<length; i++){
            if (array[i]<array[i-1]){
                int copyNum = array[i-1];
                array[i-1] = array[i];
                array[i] = copyNum;
            }
        }
        j--;
    }
    return array;
}