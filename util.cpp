#include <iostream>
#include "cards.h"
#include "game.h"
#include "util.h"
#include <stdlib.h>
#include <string.h>
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

int hand_convert(char hand[], int curPoint){
    if(strcmp(hand, "A") == 0 && curPoint <= 10){
        return 11;
    }
    if(strcmp(hand, "A") == 0 && curPoint > 10){
        return 1;
    }
    if(strcmp(hand, "2") == 0){
        return 2;
    }
    if(strcmp(hand, "3") == 0){
        return 3;
    }
    if(strcmp(hand, "4") == 0){
        return 4;
    }
    if(strcmp(hand, "5") == 0){
        return 5;
    }
    if(strcmp(hand, "6") == 0){
        return 6;
    }
    if(strcmp(hand, "7") == 0){
        return 7;
    }
    if(strcmp(hand, "8") == 0){
        return 8;
    }
    if(strcmp(hand, "9") == 0){
        return 9;
    }
    if(strcmp(hand, "10") == 0){
        return 10;
    }
    if(strcmp(hand, "J") == 0){
        return 10;
    }
    if(strcmp(hand, "Q") == 0){
        return 10;
    }
    if(strcmp(hand, "K") == 0){
        return 10;
    }
    return 0;
}

bool check_BJ(int curPoint){
    if(curPoint == 21){
        return true;
    }
    return false;
}

bool check_Busted(int curPoint){
    if(curPoint > 21){
        return true;
    }
    return false;
}