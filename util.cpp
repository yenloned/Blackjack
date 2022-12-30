#include <iostream>
#include "cards.h"
using namespace std;

void ask_actions(){
    int choice = 0;
    bool continue = true;

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
            default:
                cout << "Invalid Input, please try again"
        }
    }while(continue);
}

void ask_bet(){
    int bet = 0;

    cout << "Place your bet: ";
    do{
        cin >> bet;
        if(bet <= 0) cout << "Invalid Input, please try again"
    }while(bet <=0)
}