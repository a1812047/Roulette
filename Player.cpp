#include <iostream>
#include <string.h>
#include "Player.h"

using namespace std;

Player::Player(){
    Name = "unknown";
    chips = 200;
    number_of_bets = 0;
}

void Player::setName(string newName){
    Name = newName;
}

void Player::change_chips(int newChips){
    chips = newChips;
}

void Player::set_number_of_bets(int update){
    number_of_bets = update;
}

int Player::get_number_of_bets(){
    return number_of_bets;
}

int Player::get_chips(){
    return chips;
}

string Player::getName(){
    return Name;
}