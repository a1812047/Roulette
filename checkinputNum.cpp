#include <string>
#include <iostream>

using namespace std;

int stringtoNum(string anything){
    char* digit = &anything[0];
    int output = atoi(digit);
    return output;
}