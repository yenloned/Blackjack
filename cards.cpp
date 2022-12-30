#include "cards.h"

int* Player::get_totalHand() const { return totalHand; }

int Player::get_balance() const { return balance; }

int Player::get_totalPoint() const { return totalPoint; }

int* Player::get_splittedPoint() const { return splittedPoint; }

int* Dealer::get_totalHand() const { return totalHand; }

int Dealer::get_totalPoint() const { return totalPoint; }

int* Dealer::get_splittedPoint() const { return splittedPoint; }

