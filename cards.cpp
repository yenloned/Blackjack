#include "cards.h"
#include "util.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

Player::Player(){
    for(int i=0; i<11; i++){
        strcpy(totalHand[i],"0");
    }
    totalPoint = 0;
    
}

Player::Player(char splitedHand[], int splitedPt){
    strcpy(totalHand[0], splitedHand);
    for(int i=1; i<11; i++){
        strcpy(totalHand[i],"0");
    }
    totalPoint = splitedPt;
}

void Player::print_totalHand() const {
    int i =0;
    while(strcmp(totalHand[i], "0") != 0){
        cout << totalHand[i];
        if(i != 11 && strcmp(totalHand[i+1], "0") != 0){
            cout << ", ";
        }
        i++;
    }
}

int Player::get_totalPoint() const { return totalPoint; }

//int Player::print_splittedPoint() const { return splittedPoint; }

void Player::draw_hand(char stack[][3], int& stackSize){
    srand(time(NULL));
    int draw_post = (rand() % stackSize);
    //cout << "draw post is " << draw_post << endl;
    
    int temp = 0;
    //cout << "total[0] : " << totalHand[0] << endl;
    while(strcmp(totalHand[temp], "0") != 0){
        temp++;
    }
    strcpy(totalHand[temp], stack[draw_post]);
    //cout << "first empty place is " << temp << " getting " << *(stack+draw_post) << endl;
    totalPoint += hand_convert(totalHand[temp], get_totalPoint());

    stackSize -= 1;
    
    //delete cardStack's drawn card
    for(int i=draw_post; i < stackSize; i++){
        strcpy(stack[i], stack[i+1]);
        if(i == stackSize-1){
            strcpy(stack[i],"0");
        }
    }
}



Dealer::Dealer(){
    for(int i=0; i<11; i++){
        strcpy(totalHand[i],"0");
    }
    totalPoint = 0;
    
}

void Dealer::init_print_totalHand() const {
    cout << totalHand[0] << ", ?";
}

void Dealer::print_totalHand() const {
    int i =0;
    while(strcmp(totalHand[i], "0") != 0){
        cout << totalHand[i];
        if(i != 11 && strcmp(totalHand[i+1], "0") != 0){
            cout << ", ";
        }
        i++;
    }
}

void Dealer::init_print_totalPoint(){
    cout << hand_convert(totalHand[0], totalPoint) << " + ?";
}

int Dealer::get_totalPoint() const { return totalPoint; }

//int Dealer::get_splittedPoint() const { return splittedPoint; }

void Dealer::draw_hand(char stack[][3], int& stackSize){
    srand(time(NULL));
    int draw_post = (rand() % stackSize);
    //cout << "draw post is " << draw_post << endl;
    
    int temp = 0;
    //cout << "total[0] : " << totalHand[0] << endl;
    while(strcmp(totalHand[temp], "0") != 0){
        temp++;
    }
    strcpy(totalHand[temp], stack[draw_post]);
    //cout << "first empty place is " << temp << " getting " << *(stack+draw_post) << endl;
    totalPoint += hand_convert(totalHand[temp], get_totalPoint());

    stackSize -= 1;
    
    //delete cardStack's drawn card
    for(int i=draw_post; i < stackSize; i++){
        strcpy(stack[i], stack[i+1]);
        if(i == stackSize-1){
            strcpy(stack[i],"0");
        }
    }
}

