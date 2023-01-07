#include "game.h"

const int A = 1;
const int J = 10;
const int Q = 10;
const int K = 10;

Game::Game(){
    cardStack[52] = {};
    bet=0;
    started = false;
};

void Game::setBet(int b){
    bet = b;
};

void Game::setGameStatus(){
    if(bet > 0){
        started = true;
    }else{
        started = false;
    }
};

int Game::getBet() const{
    return bet;
}

bool Game::isGameStarted() const{
    return started;
};