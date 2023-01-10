#include <iostream>
using namespace std;

const int MAX_CARD_NUM = 11;

const int MAX_SPLITE_NUM = 3;

class Player {
    char totalHand[MAX_CARD_NUM][3];
    int totalPoint;
    char splittedPoint[MAX_SPLITE_NUM][MAX_CARD_NUM][3];

    public:
        Player();
        void print_totalHand() const;
        int get_totalPoint() const;
        int get_splittedPoint() const;
        void draw_hand(char[][3], int&);
};

class Dealer {
    char totalHand[MAX_CARD_NUM][3];
    int totalPoint;
    char splittedPoint[MAX_SPLITE_NUM][MAX_CARD_NUM][3];

    public:
        Dealer();
        void init_print_totalHand() const;
        void print_totalHand() const;
        void init_print_totalPoint();
        int get_totalPoint() const;
        int get_splittedPoint() const;
        void draw_hand(char[][3], int&);
};


