#include "game.h"

Game::Game(){
    cardStack[52] = {};
    bet=0;
    started = false;
    playerWon = false;
    draw = false;
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

void Game::playerWinning(){
    playerWon = true;
}

bool Game::isPlayerWon() const{
    return playerWon;
}

void Game::gameDraw(){
    draw = true;
}

bool Game::isGameDraw() const{
    return draw;
}