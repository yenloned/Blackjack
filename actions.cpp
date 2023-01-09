#include <iostream>
#include "game.h"
#include "cards.h"


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


