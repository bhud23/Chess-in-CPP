#include "game.h"

Game::Game (Board &b):
    head{b}, white_king{-1, -1}, black_king{-1, -1} {}

char Game::pieceAt (int x, int y) {
    return board.getTile(x, y);
}

void Game::defaultSetup (Board *head) {
    // setup white pieces
    for (int i = 0; i < 8; i++) {
        *head = new Pawn {head, i, 1, 'w'};
    }
    *head = new Rook {head, 0, 0, 'w'};
    *head = new Rook {head, 7, 0, 'w'};
    *head = new Knight {head, 1, 0, 'w'};
    *head = new Knight {head, 6, 0, 'w'};
    *head = new Bishop {head, 2, 0, 'w'};
    *head = new Bishop {head, 5, 0, 'w'};
    *head = new Queen {head, 3, 0, 'w'};
    *head = new King {head, 4, 0, 'w'};
    for (int i = 0; i < 8; i++) {
        *head = new Pawn {head, i, 1, 'b'};
    }
    *head = new Rook {head, 0, 0, 'b'};
    *head = new Rook {head, 7, 0, 'b'};
    *head = new Knight {head, 1, 0, 'b'};
    *head = new Knight {head, 6, 0, 'b'};
    *head = new Bishop {head, 2, 0, 'b'};
    *head = new Bishop {head, 5, 0, 'b'};
    *head = new Queen {head, 3, 0, 'b'};
    *head = new King {head, 4, 0, 'b'};
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