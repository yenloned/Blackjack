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

void initPrintHands(Dealer* dealer){
    cout << "Dealer's hands: "; dealer->init_print_totalHand();
    cout << " [Points: "; dealer->init_print_totalPoint(); cout << "]" << endl;
}

void printHands(Player* player){
    cout << "Player's hands: "; player->print_totalHand();
    cout << " [Points: " << player->get_totalPoint(); cout << "]" << endl;
}

void printHands(Dealer* dealer){
    cout << "Dealer's hands: "; dealer->print_totalHand();
    cout << " [Points: " << dealer->get_totalPoint(); cout << "]" << endl;
}

void checkingDealer(Player* player, Dealer* dealer, bool isPlayerBusted, bool& isDealerBusted, bool& isDealerBJ, char cardStack[][3], int& stackSize){
    cout << "===================================" << endl;
    cout << "Now checking Dealer..." << endl;
    cout << "===================================" << endl;

    isDealerBusted = check_Busted(dealer->get_totalPoint());
    isDealerBJ = check_BJ(dealer->get_totalPoint());
    bool revealed = false;
    //normal case
    while(dealer->get_totalPoint() < player->get_totalPoint() && !isPlayerBusted){
        if(isDealerBusted){
            cout << "Dealer Busted." << endl;
            break;
        }
        if(isDealerBJ){
            cout << "Dealer Blackjack!" << endl;
            break;
        }
        draw(dealer, cardStack, stackSize);
        printHands(player);
        isDealerBusted = check_Busted(dealer->get_totalPoint());
        isDealerBJ = check_BJ(dealer->get_totalPoint());
    }
    //normal case (dealer no need to draw)
    if(dealer->get_totalPoint() > player->get_totalPoint() && !isPlayerBusted){
        if(isDealerBusted){
            cout << "Dealer Busted." << endl;
        }
        else if(isDealerBJ){
            cout << "Dealer Blackjack!" << endl;
        }else{
            printHands(dealer);
        }
        
    }
    //player busted (dealer need to pass 17)
    while(dealer->get_totalPoint() < 17 && isPlayerBusted){
        revealed = true;
        draw(dealer, cardStack, stackSize);
        printHands(player);
        isDealerBusted = check_Busted(dealer->get_totalPoint());
    }
    //player busted (dealer passed 17 already)
    if(dealer->get_totalPoint() > 17 && isPlayerBusted && !revealed){
        if(isDealerBusted){
            cout << "Dealer Busted." << endl;
        }else{
            printHands(dealer);
        }
    }
}

void result(Player* player, Dealer* dealer, Game* blackjack, bool isPlayerBusted, bool isPlayerBJ, bool isDealerBusted, bool isDealerBJ, int bet){

    if(!isPlayerBusted && isDealerBusted) blackjack->playerWinning();
        if(isPlayerBJ && !isDealerBJ) blackjack->playerWinning();
        if(!isPlayerBusted && player->get_totalPoint() > dealer->get_totalPoint()) blackjack->playerWinning();
        if(isPlayerBJ && isDealerBJ) blackjack->gameDraw();
        if(isPlayerBusted && isDealerBusted) blackjack->gameDraw();
        if(player->get_totalPoint() == dealer->get_totalPoint()) blackjack->gameDraw();


        if(blackjack->isGameDraw()){
            cout << "Draw. You got back $" << bet << "." << endl;
            return;
        }
        if(blackjack->isPlayerWon()){
            cout << "You won $" << bet*2 << "." << endl;
        }else{
            cout << "You lost $" << bet << "." << endl;
        }
}

void gameEnd(){
    char temp;
    cout << "Input any keys to quit...";
    cin >> temp;
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
    bool ableToSplit = checkCanSplit(player->getFirstHand(), player->getSecHand());
    bool ableToDouble = true;
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
            ableToSplit = false;
            ableToDouble = false;
            break;
        case 2:
            break;
        case 3:
            if(ableToDouble){
                draw(player, cardStack, stackSize);
                initPrintHands(dealer);
                bet *= 2;
                ableToSplit = false;
                break;
            }else{
                cout << "Invalid move, unable to double down in non-first round." << endl;
                break;
            }
        case 4:
            if(ableToSplit){
                break;
            }else{
                cout << "Invalid move, unable to split this pair of hand." << endl;
                continue;
            }
        }
        isPlayerBusted = check_Busted(player->get_totalPoint());
        isPlayerBJ = check_BJ(player->get_totalPoint());
        if(main_choice == 3) break;
    }
    //Non-split case
    if(main_choice != 4){
        //player result
        if(isPlayerBusted) cout << "Player Blusted." << endl;
        if(isPlayerBJ) cout << "Blackjack!" << endl;

        bool isDealerBusted = check_Busted(dealer->get_totalPoint());
        bool isDealerBJ = check_BJ(dealer->get_totalPoint());
        //checking dealer
        checkingDealer(player, dealer, isPlayerBusted, isDealerBusted, isDealerBJ, cardStack, stackSize);

        //final result
        cout << "===================================" << endl;
        cout << "Result" << endl;
        cout << "===================================" << endl;
        result(player, dealer, blackjack, isPlayerBusted, isPlayerBJ, isDealerBusted, isDealerBJ, bet);

    }else{
    //Split case
        int split_choice1, split_choice2 = 0;
        int split_switch = 1;
        bool isPlayerStanded = false;
        bool isPlayer2Standed = false;
        bool playerAbleToDouble = true;
        bool player2AbleToDouble = true;
        bool isPlayerDoubled = false;
        bool isPlayer2Doubled = false;
        bool isPlayer2Busted = false;
        bool isPlayer2BJ = false;
        Player* player2 = new Player(player);
        player->deleteSecHand();
        player2->deleteSecHand();

        while((!isPlayerBJ && !isPlayerBusted && !isPlayerStanded) || (!isPlayerBJ && !isPlayerBusted && !isPlayer2Standed)){
            if(split_switch == 1 && !isPlayerStanded && !isPlayerDoubled){
                splitAction(player, dealer, cardStack, stackSize, playerAbleToDouble, isPlayerBusted, isPlayerBJ, isPlayerStanded, isPlayerDoubled);
            }else if(split_switch == 2 && !isPlayer2Standed && !isPlayer2Doubled){
                splitAction(player2, dealer, cardStack, stackSize, player2AbleToDouble, isPlayer2Busted, isPlayer2BJ, isPlayer2Standed, isPlayer2Doubled);
            }
            if(split_switch == 1){
                split_switch = 2;
            }else{
                split_switch = 1;
            }
        }

        bool isDealerBusted = check_Busted(dealer->get_totalPoint());
        bool isDealerBJ = check_BJ(dealer->get_totalPoint());
        Dealer* temp_dealer = dealer;
        //checking dealer
        checkingDealer(player, dealer, isPlayerBusted, isDealerBusted, isDealerBJ, cardStack, stackSize);
        checkingDealer(player2, temp_dealer, isPlayerBusted, isDealerBusted, isDealerBJ, cardStack, stackSize);

        //final result
        cout << "===================================" << endl;
        cout << "Result for Hand1" << endl;
        cout << "===================================" << endl;
        result(player, dealer, blackjack, isPlayerBusted, isPlayerBJ, isDealerBusted, isDealerBJ, bet/2);
        cout << endl;
        cout << "===================================" << endl;
        cout << "Result for Hand2" << endl;
        cout << "===================================" << endl;
        result(player2, dealer, blackjack, isPlayer2Busted, isPlayer2BJ, isDealerBusted, isDealerBJ, bet/2);
    }


    blackjack = nullptr;
    delete blackjack;
    player = nullptr;
    delete player;
    dealer = nullptr;
    delete dealer;

    gameEnd();

    return 0;
}