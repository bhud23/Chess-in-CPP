#include "game.h"

Game::Game (Board *b):
    head{b}, white_king{-1, -1}, black_king{-1, -1} {}

char Game::pieceAt (int x, int y) {
    return head->getTile(x, y);
}

void Game::defaultSetup (Board **head) {
    // setup white pieces
    for (int i = 0; i < 8; i++) {
        *head = new Pawn {*head, i, 1, 'w'};
    }
    *head = new Rook {*head, 0, 0, 'w'};
    *head = new Rook {*head, 7, 0, 'w'};
    *head = new Knight {*head, 1, 0, 'w'};
    *head = new Knight {*head, 6, 0, 'w'};
    *head = new Bishop {*head, 2, 0, 'w'};
    *head = new Bishop {*head, 5, 0, 'w'};
    *head = new Queen {*head, 3, 0, 'w'};
    *head = new King {*head, 4, 0, 'w'};
    white_king.first = 4;
    white_king.second = 0;
    // setup black pieces
    for (int i = 0; i < 8; i++) {
        *head = new Pawn {*head, i, 6, 'b'};
    }
    *head = new Rook {*head, 0, 7, 'b'};
    *head = new Rook {*head, 7, 7, 'b'};
    *head = new Knight {*head, 1, 7, 'b'};
    *head = new Knight {*head, 6, 7, 'b'};
    *head = new Bishop {*head, 2, 7, 'b'};
    *head = new Bishop {*head, 5, 7, 'b'};
    *head = new Queen {*head, 4, 7, 'b'};
    *head = new King {*head, 3, 7, 'b'};
    black_king.first = 3;
    black_king.second = 7;
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
