#include <iostream>
using namespace std;

const int MAX_CARD_NUM = 52;

const int SPILTE_NUM = 26;

class Player {
    int totalHand[MAX_CARD_NUM];
    int balance;
    int totalPoint;
    int splittedPoint[SPILTE_NUM];

    public:
        Player();
        int get_totalHand() const;
        int get_balance() const;
        int get_totalPoint() const;
        int get_splittedPoint() const;
        void draw_hand(int*, int&);
};

class Dealer {
    int totalHand[MAX_CARD_NUM];
    int totalPoint;
    int splittedPoint[SPILTE_NUM];

    public:
        Dealer();
        int get_totalHand() const;
        int get_totalPoint() const;
        int get_splittedPoint() const;
        void draw_hand();
};


