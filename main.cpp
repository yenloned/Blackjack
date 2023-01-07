#include <iostream>
#include "util.h"
#include "game.h"
#include "cards.h"
using namespace std;

//g++ main.cpp cards.cpp game.cpp util.cpp

const int A = 1;
const int J = 10;
const int Q = 10;
const int K = 10;
int initCardStack[52] = {A,A,A,A,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,J,J,J,J,Q,Q,Q,Q,K,K,K,K};
int* cardStack = initCardStack;

void showCurrentBet(int bet){
    cout << "Current Bet: " << bet << endl;
}

int main(){

    int stackSize = 52;

    Game* blackjack = new Game;
    Player* player = new Player;
    Dealer* dealer = new Dealer;

    while(!blackjack->isGameStarted()){
        int bet = ask_bet();
        blackjack->setBet(bet);
        blackjack->setGameStatus();
    }

    showCurrentBet(blackjack->getBet());
    int choice = ask_actions();

    player->draw_hand(cardStack, stackSize);

    cout << player->get_totalHand() << endl;

    return 0;
}