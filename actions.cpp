#include <iostream>
#include "game.h"
#include "cards.h"


using namespace std;

void draw(Dealer* dealer, char cardStack[][3], int& stackSize){
    dealer->draw_hand(cardStack, stackSize);
}

void draw(Player* player, char cardStack[][3], int& stackSize){
    player->draw_hand(cardStack, stackSize);
}


