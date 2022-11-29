#include "gamemanager.h"

char GameManager::getTitle (int x1, int y1) {
    return (*theBoard)->getPiece(x1, y1);
}

Board **GameManager::board () {
    return theBoard;
}

GameManager::~GameManager () {
    delete *theBoard;
}