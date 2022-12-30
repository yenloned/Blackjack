#include <iostream>
using namespace std;

const int A = 1;
const int J = 10;
const int Q = 10;
const int K = 10;

const int CARD_NUM = 52;

int initCardStack[CARD_NUM] = [A,A,A,A,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,J,J,J,J,Q,Q,Q,Q,K,K,K,K]

class Game {
    int cardStack[CARD_NUM];
    int bet;

    public:
        Game(int cardStack[]);
        void setBet(int b);
}