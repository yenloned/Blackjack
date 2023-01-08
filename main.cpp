#include <iostream>
#include "util.h"
#include "game.h"
#include "cards.h"
#include "actions.h"
using namespace std;

//g++ main.cpp cards.cpp game.cpp util.cpp actions.cpp

char cardStack[52][3] = {"A","A","A","A","2","2","2","2","3","3","3","3","4","4","4","4","5","5","5","5","6","6","6","6","7","7","7","7","8","8","8","8","9","9","9","9","10","10","10","10","J","J","J","J","Q","Q","Q","Q","K","K","K","K"};

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
    draw(dealer, cardStack, stackSize);
    draw(dealer, cardStack, stackSize);
    draw(player, cardStack, stackSize);
    draw(player, cardStack, stackSize);

    cout << "Dealer's hands: "; dealer->init_print_totalHand();
    cout << "Dealer's points: "; dealer->init_print_totalPoint();
    cout << "Player's hands: "; player->print_totalHand();
    cout << "Player's points: " << player->get_totalPoint(); cout << endl;

    int choice = 0;
    while(choice != 2 && player->get_totalPoint() <= 21){
        choice = ask_actions();
        switch (choice){
        case 1:
            draw(player, cardStack, stackSize);
            break;
        case 2:
            break;
        case 3:
            draw(player, cardStack, stackSize);
            break;
        case 4:

        }
        if(choice == 3) break;
    }

    return 0;
}