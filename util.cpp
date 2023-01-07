#include <iostream>
#include "cards.h"
#include "game.h"
#include "util.h"
using namespace std;

int ask_actions(){
    int choice = 0;
    bool is_continue = true;

    do{
        cout << "===================================" << endl;
        cout << "Choose what to do next:" << endl;
        cout << "1: Hit" << endl;
        cout << "2: Stand" << endl;
        cout << "3: Double down" << endl;
        cout << "4: Split:" << endl;
        cout << "===================================" << endl;
        cin >> choice;

        switch(choice){
            case 1: is_continue = false; break;
            case 2: is_continue = false; break;
            case 3: is_continue = false; break;
            case 4: is_continue = false; break;
            default:
                cout << "Invalid Input, please try again." << endl;
        }
    }while(is_continue);

    return choice;
}

int ask_bet(){
    int bet = 0;

    cout << "Place your bet: ";
    do{
        cin >> bet;
        if(bet <= 0) cout << "Invalid Input, please try again." << endl;
    }while(bet <=0);
    return bet;
}