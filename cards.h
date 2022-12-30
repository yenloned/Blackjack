#include <iostream>
using namespace std;

const int CARD_NUM = 52;

const int SPILTE_NUM = 26;

class Player {
    int totalHand[CARD_NUM];
    int balance;
    int totalPoint;
    int splittedPoint[SPILTE_NUM];

    public:
        int* get_totalHand() const;
        int get_balance() const;
        int get_totalPoint() const;
        int* get_splittedPoint() const;
};

class Dealer {
    int totalHand[CARD_NUM];
    int totalPoint;
    int spiltedPoint[SPILTE_NUM];

    public:
        int get_totalHand() const;
        int get_totalPoint() const;
        int get_splittedPoint() const;
};


