#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;


int random_num(int num ){
    srand(time(0));
    int randomNumber = rand()%num;
    return randomNumber;   
}
    
    