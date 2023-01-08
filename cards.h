#include <iostream>
using namespace std;

const int MAX_CARD_NUM = 52;

const int SPILTE_NUM = 26;

class Player {
    char totalHand[MAX_CARD_NUM][3];
    int balance;
    int totalPoint;
    int splittedPoint[SPILTE_NUM];

    public:
        Player();
        void print_totalHand() const;
        int get_balance() const;
        int get_totalPoint() const;
        int get_splittedPoint() const;
        void draw_hand(char[][3], int&);
};

class Dealer {
    char totalHand[MAX_CARD_NUM][3];
    int totalPoint;
    int splittedPoint[SPILTE_NUM];

    public:
        Dealer();
        void init_print_totalHand() const;
        void print_totalHand() const;
        void init_print_totalPoint();
        int get_totalPoint() const;
        int get_splittedPoint() const;
        void draw_hand(char[][3], int&);
};


