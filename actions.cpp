#include <iostream>
#include "game.h"
#include "cards.h"
#include "util.h"
#include <string.h>


using namespace std;

void initDrawForDealer(Dealer* dealer, char cardStack[][3], int& stackSize){
    cout << "Drawing a card for Dealer..." << endl;
    dealer->draw_hand(cardStack, stackSize);
    cout << "Drawing a card for Dealer..." << endl;
    dealer->draw_hand(cardStack, stackSize);
    cout << "Dealer's hands: "; dealer->init_print_totalHand();
    cout << " [Points: "; dealer->init_print_totalPoint(); cout << "]" << endl;
}

void draw(Dealer* dealer, char cardStack[][3], int& stackSize){
    cout << "Drawing a card for Dealer..." << endl;
    dealer->draw_hand(cardStack, stackSize);
    cout << "Dealer's hands: "; dealer->print_totalHand();
    cout << " [Points: " << dealer->get_totalPoint(); cout << "]" << endl;
}

void draw(Player* player, char cardStack[][3], int& stackSize){
    cout << "Drawing a card for Player..." << endl;
    player->draw_hand(cardStack, stackSize);
    cout << "Player's hands: "; player->print_totalHand();
    cout << " [Points: " << player->get_totalPoint(); cout << "]" << endl;
}

bool checkCanSplit(const char hands[], const char secHands[]){
    if(strcmp(hands, secHands) == 0) return true;
    return false;
}

void split(const char hands[], const char secHands[]){

}

void splitAction(Player* player, Dealer* dealer, char cardStack[][3], int& stackSize, bool& ableToDouble, bool& isPlayerBusted, bool& isPlayerBJ, bool& isPlayedStanded, bool& isPlayerDoubled){
    int split_choice = ask_actions();
    switch (split_choice){
    case 1:
        draw(player, cardStack, stackSize);
        //printInitHands
        cout << "Dealer's hands: "; dealer->init_print_totalHand();
        cout << " [Points: "; dealer->init_print_totalPoint(); cout << "]" << endl;
        ableToDouble = false;
        break;
    case 2:
        isPlayedStanded = true;
        break;
    case 3:
        if(ableToDouble){
            draw(player, cardStack, stackSize);
            //printInitHands
            cout << "Dealer's hands: "; dealer->init_print_totalHand();
            cout << " [Points: "; dealer->init_print_totalPoint(); cout << "]" << endl;
            isPlayerDoubled = true;
            break;
        }else{
            cout << "Invalid move, unable to double down in non-first round." << endl;
            break;
        }
    case 4:
        cout << "Invalid move, unable to Split again." << endl;
        break;
    }
    isPlayerBusted = check_Busted(player->get_totalPoint());
    isPlayerBJ = check_BJ(player->get_totalPoint());
}


