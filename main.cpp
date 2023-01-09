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

void printHands(Player* player){
    cout << "Player's hands: "; player->print_totalHand();
    cout << " [Points: " << player->get_totalPoint(); cout << "]" << endl;
}

void printHands(Dealer* dealer){
    cout << "Dealer's hands: "; dealer->print_totalHand();
    cout << " [Points: " << dealer->get_totalPoint(); cout << "]" << endl;
}

void initPrintHands(Dealer* dealer){
    cout << "Dealer's hands: "; dealer->init_print_totalHand();
    cout << " [Points: "; dealer->init_print_totalPoint(); cout << "]" << endl;
}


int main(){

    int stackSize = 52;

    Game* blackjack = new Game;
    Player* player = new Player;
    Dealer* dealer = new Dealer;
    int bet = 0;

    while(!blackjack->isGameStarted()){
        bet = ask_bet();
        blackjack->setBet(bet);
        blackjack->setGameStatus();
    }
    showCurrentBet(blackjack->getBet());
    initDrawForDealer(dealer, cardStack, stackSize);
    draw(player, cardStack, stackSize);
    draw(player, cardStack, stackSize);

    int main_choice = 0;
    bool isPlayerBusted = false;
    bool isPlayerBJ = false;
    isPlayerBJ = check_BJ(player->get_totalPoint());

    while(main_choice != 2 && player->get_totalPoint() <= 21){
        if(isPlayerBJ || isPlayerBusted) break;
        main_choice = ask_actions();
        switch (main_choice){
        case 1:
            draw(player, cardStack, stackSize);
            initPrintHands(dealer);
            break;
        case 2:
            break;
        case 3:
            draw(player, cardStack, stackSize);
            initPrintHands(dealer);
            break;
        }
        if(main_choice == 3) break;
        isPlayerBusted = check_Busted(player->get_totalPoint());
        isPlayerBJ = check_BJ(player->get_totalPoint());
    }
    //player result
    if(isPlayerBusted) cout << "Player Blusted." << endl;
    if(isPlayerBJ) cout << "Blackjack!" << endl;

    //check dealer
    cout << "===================================" << endl;
    cout << "Now checking Dealer..." << endl;
    cout << "===================================" << endl;

    bool isDealerBusted = false;
    bool isDealerBJ = false;
    //normal case
    while(dealer->get_totalPoint() < player->get_totalPoint() && !isPlayerBusted){
        if(isDealerBusted || isDealerBJ) break;
        draw(dealer, cardStack, stackSize);
        printHands(player);
        isDealerBusted = check_Busted(dealer->get_totalPoint());
        isDealerBJ = check_BJ(dealer->get_totalPoint());
    }
    //player busted (dealer need to pass 17)
    while(dealer->get_totalPoint() < 17 && isPlayerBusted){
        draw(dealer, cardStack, stackSize);
        printHands(player);
        isDealerBusted = check_Busted(dealer->get_totalPoint());
    }

    //final result
    cout << "===================================" << endl;
    cout << "Result" << endl;
    cout << "===================================" << endl;
    if(!isPlayerBusted && isDealerBusted) blackjack->playerWinning();
    if(isPlayerBJ && !isDealerBJ) blackjack->playerWinning();
    if(!isPlayerBusted && player->get_totalPoint() > dealer->get_totalPoint()) blackjack->playerWinning();


    if(blackjack->isGameDraw()){
        cout << "Draw. You got back $" << bet << "." << endl;
        return 0;
    }
    if(blackjack->isPlayerWon()){
        cout << "You won $" << bet*2 << "." << endl;
    }else{
        cout << "You lost $" << bet << "." << endl;
    }

    return 0;
}