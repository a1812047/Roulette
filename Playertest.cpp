#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include "ODD_EVEN.h"
#include "Player.h"
#include "Single.h"
#include "DOZENS.h"
#include "red_black.h"
#include "first18vslast18.h"

extern int stringtoNum(string );
extern int random_num(int num );
extern void display_bets();

using namespace std;


int main(){

    int begin;
    cout<<"*******************************Welcome to the game of Roulette*****************************"<<endl;
    cout<<'\n'<<'\n'<<'\n'<<'\n'<<endl;


    cout<<"To play press 1 or press 2 to quit."<<endl;
    cin>>begin;
    if (begin !=1){
        cout<<"Exiting...."<<endl;
        return -1;




    }
    else{
        // The Player object is formed and it is alloted 200 chips to begin with.
        Player* player = new Player();
        cout<<"Enter your name:"<<endl;
        string name;
        cin>>name;
        player->setName(name);
        cout<<"Hi "<<player->getName()<<" .You have "<<player->get_chips()<<" at hand to begin with."<<endl;
        cout<<"Here is the Game Board at display"<<endl;





        bool play_games = true;
        while (play_games == true){

            Roulette* gameA;
            gameA->display_the_table();
            //cout<<gameA->get_Outcome()<<endl;

            display_bets();//a function used to show the subclasses printed as options to the player.








            //player chooses the game
            enum chosen_num{
                odd_even =1,
                single_number ,
                Red_black ,
                dozens,
                eighteens,
                quit
            };




            //player chose the game and
            //We now create the subclass accordingly.


            int chosen_game = 10;//let the chosen game be 10, : not, the right number.

            while((chosen_game > quit) || (chosen_game<odd_even )){
                //if the chosen_game is not the right number, ask for input
                cout<<'\n'<<"Enter the respective number: ";

                string garbage_check;//the user input is taken as string to check if the input is a garbage.
                cin>>garbage_check;
                stringstream(garbage_check)>>chosen_game;

                if(chosen_game >quit){
                    cout<<"Wrong number!! Press 6 to quit, if you dont want to play, else choose from 1-5"<<endl;
                }else if(chosen_game <odd_even){
                    cout<<"Wrong Input!!!!"<<endl;
                }
            }





            // now the subclass behaviours and state is allocated to the class Roulette game
            //Polymorphism.
            // so the function will react accordingly.
            if (chosen_game == odd_even){
                gameA = new ODD_EVEN();//object for playing the game of odd or even
            }else if (chosen_game == single_number){
                gameA = new SINGLE(); //object for playing the game of Single Numbers
            }else if(chosen_game == quit){
                return -1;
            }else if(chosen_game == dozens){
                gameA = new DOZENS();
            }else if(chosen_game == Red_black){
                gameA = new red_black();
            }else if(chosen_game == eighteens){
                gameA = new first18vslast18();
            }
            gameA->display_the_table();// display function used again to display the game table continuously.





            //get the game going;

            while(gameA->total_bet==0){

                gameA->playgame(player);// prints out different for different games.
                //here function of the subclass games are used.
                }


            gameA->setBin();//function that describes
            //the bin of numbers the player bets on:  according to the type of subclass created(use of virtual)


            cout<<"total bet = "<<gameA->total_bet<<endl;
            cout<<'\n'<<endl; // displays the final bet.


            cout<<"It is time to spin the wheel : "<<endl;
            cout<<"Press any key and hit enter to spin the wheel: ";
            string garbage;
            cin>>garbage;

            //another function linked externally
            int spin_the_wheel = random_num(size_of_board);//.captures the random number and stores in spin_the_wheel.

            int win = gameA->payout(spin_the_wheel);//calculates the payout for the respective subclass(or game).(virtual method)


            //distributing the chips for the player.
            int remaining_chips = player->get_chips();
            player->change_chips(remaining_chips+win);



            cout<<'\n'<<"the wheel stopped at "<<spin_the_wheel<<'\n';

            cout<<'\n';
            gameA->print_Outcome(spin_the_wheel);


            cout<<'\n'<<'\n'<<"You now have "<<"("<<remaining_chips<<"+"<<win<<") = "<<player->get_chips()<<" at hand"<<'\n'<<'\n'<<endl;
            delete gameA;//game subclass is destroyed.







            string play_more;//ask if the player wants to continue??
            if(player->get_chips()>0){//but it is only possible if the player still has the money.
                cout<<"Do you wanna play another round??"<<'\n';
                cout<< "press Y for yes or N for no: ";
                cin>>play_more;
                while((play_more != "Y") && (play_more != "y") && (play_more != "N") && (play_more != "n")){
                    cout<<"Wrong input!!!!!!!"<<endl;
                    cout<< "press Y for yes or N for no: ";
                    cin>>play_more;
                }
            }else{//if chips == 0
                cout<<"Sorry, YOU LOST ALL THE CHIPS!!"<<endl;
                play_games = false;
                break;
            }

            if((play_more == "y") || (play_more == "Y")){
                play_games = true;//takes it back to the beginning.
            }else{
                play_games = false;//the loop ends here.
            }
        }
    }
 return 0;
}