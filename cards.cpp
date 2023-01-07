#include "cards.h"
#include <stdlib.h>
#include <time.h>

const int A = 1;
const int J = 10;
const int Q = 10;
const int K = 10;

Player::Player(){
    for(int i=0; i<11; i++){
        totalHand[i] = 0;
    }
    balance = 10000;
    totalPoint = 0;
    splittedPoint[26] = {};
}

int Player::get_totalHand() const { return totalHand[0]; }

int Player::get_balance() const { return balance; }

int Player::get_totalPoint() const { return totalPoint; }

//int Player::get_splittedPoint() const { return splittedPoint; }

void Player::draw_hand(int* stack, int& stackSize){
    srand(time(NULL));
    int draw_post = (rand() % stackSize);
    //cout << "draw post is " << draw_post << endl;
    
    int temp = 0;
    //cout << "total[0] : " << totalHand[0] << endl;
    while(totalHand[temp] != 0){
        temp++;
    }
    totalHand[temp] = *(stack+draw_post);
    //cout << "first empty place is " << temp << " getting " << *(stack+draw_post) << endl;
    totalPoint += totalHand[temp];

    stackSize -= 1;
    
    //delete cardStack's drawn card
    for(int i=draw_post; i < stackSize; i++){
        stack[i] = stack[i+1];
    }
}



Dealer::Dealer(){
    totalHand[11] = {};
    totalPoint = 0;
    splittedPoint[26] = {};
}

//int Dealer::get_totalHand() const { return totalHand; }

int Dealer::get_totalPoint() const { return totalPoint; }

//int Dealer::get_splittedPoint() const { return splittedPoint; }

