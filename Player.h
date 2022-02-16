#include <iostream>
#include <string>

using namespace std;



#ifndef PLAYER_H
#define PLAYER_H

class Player{
    private:
    int chips;
    string Name;
    int number_of_bets;
    public:
    Player();
    void setName(string);
    string getName();
    void change_chips(int);
    int get_chips();
    void set_number_of_bets(int);
    int get_number_of_bets();
    ~Player();
    
};

#endif