#include <iostream>
using namespace std;

class Game {
    bool started;
    int cardStack[52];
    int bet;
    bool playerWon;
    bool draw;

    public:
        Game();
        void setBet(int b);
        void setGameStatus();
        bool isGameStarted() const;
        int getBet() const;
        void gameSwitch();
        void playerWinning();
        bool isPlayerWon() const;
        void gameDraw();
        bool isGameDraw() const;
};