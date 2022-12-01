#include "game.h"

Game::Game (Board &b):
    head{b}, white_king{-1, -1}, black_king{-1, -1} {}

char Game::pieceAt (int x, int y) {
    return board.getTile(x, y);
}

void Game::defaultSetup (Board &head) {
    // setup white pieces
    for (int i = 0; i < 8; i++) {
        head = new Pawn {, &head, i, 1, 'w'};
    }
    // setup black pieces
}

void Game::movePiece (int x1, int y1, int x2, int y2) {
    return;
}

bool Game::isCheck (char team) {
    return false;
}

bool Game::isCheckMate (char team) {
    return false;
}

bool Game::isStalemate() {
    return false;
}

void Game::printScore () {
    return;
}